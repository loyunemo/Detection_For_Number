#include "Functions.h"

//MotorPID

PIDTypeDef hpid_lmotor={MT_Kp,MT_Ki,MT_Kd,0,0,0,MT_up,MT_down};
PIDTypeDef hpid_rmotor={MT_Kp,MT_Ki,MT_Kd,0,0,0,MT_up,MT_down};
int16_t Loutput,Routput;

void SetMotorOutputPID(int16_t Lspeed,int16_t Rspeed)
{
		Loutput = PID_Compute(&hpid_lmotor, Lspeed, encoderL_10ms);
    Routput = PID_Compute(&hpid_rmotor, Rspeed, encoderR_10ms);
    SetMotorOutput(Loutput, Routput);
}

void MotorOutputPIDClear()
{
	PID_DeInit(&hpid_lmotor);
	PID_DeInit(&hpid_rmotor);
}

//Turn

uint8_t turn_count=0;

uint8_t Turn(int8_t Dir,uint8_t count)
{
	static uint8_t flag=1;
	EncoderCallBack();
	GrayScalerCallBack();
	if((flag==1)&&(sensor_count==0))
	{
		flag=0;
	}
	if((sensor_count!=0)&&(flag==0))
	{
		flag=1;
		if(count==++turn_count)
		{
			flag=1;
			turn_count=0;
			FollowLineClearLineCount();
			return END;
		}
	}
	if(Dir==TU_TB)
	{
		SetMotorOutputPID(TURNSPEED,-TURNSPEED);
	}
	else
	{	
		SetMotorOutputPID(-Dir*TURNSPEED,Dir*TURNSPEED);
	}
	return CONTINUE;
}

//Path

uint8_t Path[20]={
	'F','F','F',
'L','T','T','L','F','F'};
uint8_t Path_now=0;
uint8_t Path_act=0;
uint8_t Path_on=0;

uint8_t Path_turn_flag=0;

void GoPath()
{
	Path_act=Path[Path_now];
	if(Path_on==0)
	{
		return;
	}
	switch(Path_act)
	{
		case 0:
		{
			if(FollowLineForLengthCallBack(SPEED,LENGTH))
			{
				MotorOutputPIDClear();
				Path_now++;
				Path_on=0;
			}
			break;
		}
		case 'F':
		{
			if(FollowLinePIDCallBack(SPEED))
			{
				MotorOutputPIDClear();
				Path_now++;
			}
			break;
		}
		case 'L':
		{
			if(sensor[4]&&Path_turn_flag==0)
			{
				Path_turn_flag=1;
			}
			if(Path_turn_flag)
			{
				if(Turn(TU_CC,1)){
					MotorOutputPIDClear();
					Path_turn_flag=0;Path_now++;
					break;
				}
				break;
			}
			FollowLinePIDCallBack(SPEED);
			break;
		}
		case 'R':
		{
			if(sensor[5]&&Path_turn_flag==0)
			{
				Path_turn_flag=1;
			}
			if(Path_turn_flag)
			{
				if(Turn(TU_CW,1)){
					MotorOutputPIDClear();
					Path_turn_flag=0;Path_now++;
					break;
				}
				break;
			}
			FollowLinePIDCallBack(SPEED);
			break;
		}
		case 'T':
		{
			if(sensor[4]&&Path_turn_flag==0)
			{
				Path_turn_flag=1;
			}
			if(Path_turn_flag)
			{
				if(Turn(TU_TB,2)) {
					MotorOutputPIDClear();
					Path_turn_flag=0;Path_now++;
					break;
				}
				break;
			}
			FollowLinePIDCallBack(SPEED);
			break;
		}
	}
}
