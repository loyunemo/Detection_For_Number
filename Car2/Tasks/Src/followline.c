/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-07-17 07:41:10
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-07-17 08:38:25
 * @FilePath: \Explorerss\Tasks\Src\followline.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "followline.h"

PIDTypeDef hpid_followline;
PIDTypeDef *hpid_lmotor_follow, *hpid_rmotor_follow;

float sensor_input=0;
float sensor_output=0;
float lsensor=0,rsensor=0; 
uint8_t lsensor_count,rsensor_count;

uint8_t line_count=0;
uint8_t last_line_count=0;
uint8_t line_flag=0;//记线数标志位

void FollowLinePID_Init(void)
{
    PID_Init(&hpid_followline);
    hpid_followline.ref = 0;
    hpid_followline.Kp = FL_Kp;
    hpid_followline.Ki = FL_Ki;
    hpid_followline.Kd = FL_Kd;
	
		line_count=0;
		last_line_count=0;
		line_flag=0;

    GrayScaler_Init();
}

void FollowLineRememberLineClear(void)
{
	sensor_input=0;
}

uint8_t FollowLinePIDCallBack(int MotorSpeed)
{
//		sensor_input=0;//注释此句使得记住状态
		lsensor=0,rsensor=0; 
		lsensor_count=sensor[0]+sensor[1];
		rsensor_count=sensor[2]+sensor[3];
		if(sensor_count!=0)
		{
			if(lsensor_count>0)
			lsensor=(float)(3*sensor[0]+sensor[1])/(float)lsensor_count;
			if(rsensor_count>0)
			rsensor=(float)(3*sensor[3]+sensor[2])/(float)rsensor_count;
			sensor_input = rsensor-lsensor;//灰度传感器在PID中的输入量
		}
//    sensor_output=PID_ComputeFixed(&hpid_followline, sensor_count?sensor_input*1.5:sensor_input);
		sensor_output=PID_ComputeFixed(&hpid_followline, fabs(fabs(sensor_input)-3)<1e-7?sensor_input*1.33:0);
		
		
		SetMotorOutputPID(MotorSpeed-sensor_output,MotorSpeed+sensor_output);
		
		last_line_count=line_count;
		if((sensor_count==4)&&(line_flag==0))
		{
			line_flag=1;
			++line_count;
		}
		if((line_flag==1)&&(sensor_count!=4))
		{
			line_flag=0;
		}
		
		if(line_count!=last_line_count)
		{
			return END;
		}
		return CONTINUE;
}

void FollowLineClearLineCount(void)
{
	line_count=0;
	last_line_count=line_count;
	line_flag=0;
}

uint8_t FollowLineForLengthCallBack(int MotorSpeed,uint32_t encoder_len)
{
	static uint32_t encoder_count_follow=0;
	FollowLinePIDCallBack(MotorSpeed);
	encoder_count_follow+=(encoderL_10ms+encoderR_10ms)/2;
	if(encoder_count_follow>encoder_len)
	{
		encoder_count_follow=0;
		return END;
	}
	else 
	{
		return CONTINUE;
	}
}


