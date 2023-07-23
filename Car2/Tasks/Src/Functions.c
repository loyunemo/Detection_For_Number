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

uint8_t SetMotorOutputEncoder(int16_t encoderL,int16_t encoderR,int16_t time_ms){
	int16_t Lspeed=encoderL/time_ms;
	int16_t Rspeed=encoderR/time_ms;
	static int32_t encoderL_count=0;
	static int32_t encoderR_count=0;
	encoderL_count+=encoderL_10ms;
	encoderR_count+=encoderR_10ms;
	int16_t Lremain=abs(encoderL_count)-abs(encoderL);
	int16_t Rremain=abs(encoderR_count)-abs(encoderR);
	if(Lremain>0&&Rremain>0)
	{
		MotorOutputPIDClear();
		encoderL_count=0;
		encoderR_count=0;
		SetMotorOutput(0,0);
		return END;
	}
	SetMotorOutputPID(Lremain>0?0:Lspeed,Rremain>0?0:Rspeed);
	return CONTINUE;
}

void MotorOutputPIDClear()
{
	PID_DeInit(&hpid_lmotor);
	PID_DeInit(&hpid_rmotor);
}

//Turn

uint8_t Turn(int8_t Dir)
{
	if(Dir==TU_TB)
	{
		return SetMotorOutputEncoder(FULLTURN,-FULLTURN,1000);
	}
	else{
		return SetMotorOutputEncoder(-Dir*HALFTURN,Dir*HALFTURN,500);
	}
}

uint8_t ForwardTurn(int8_t Dir)
{
	static uint8_t Path_turn_flag=0;
	if(sensor[4]&&(Path_turn_flag==0))
	{
		Path_turn_flag=1;
		MotorOutputPIDClear();
	}
	if(Path_turn_flag)
	{
		if(Turn(TU_CC)){
			MotorOutputPIDClear();
			Path_turn_flag=0;Path_now++;
			return END;
		}
		return CONTINUE;
	}
	FollowLineRememberLineClear();
	FollowLinePIDCallBack(FORTURNSPEED);
	return CONTINUE;
}

//Path

uint8_t Path[20]={
	'F','F','F',
'L','F','T','F','T','L','F','F'
//'F','T','F','T','F','T','F','T','F','T','F','T','F','T'
//	'T','T','T','T','T','T','T'
//	'F','L','T','R','F'
};
uint8_t Path_now=0;
uint8_t Path_act=0;
uint8_t Path_on=1;

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
			SetMotorOutput(0,0);
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
			if(sensor[4]&&(Path_turn_flag==0))
			{
				Path_turn_flag=1;
				MotorOutputPIDClear();
			}
			if(Path_turn_flag)
			{
				if(Turn(TU_CC)){
					MotorOutputPIDClear();
					Path_turn_flag=0;Path_now++;
					break;
				}
				break;
			}
			FollowLineRememberLineClear();
			FollowLinePIDCallBack(FORTURNSPEED);
			break;
		}
		case 'R':
		{
			if(sensor[5]&&(Path_turn_flag==0))
			{
				Path_turn_flag=1;
				MotorOutputPIDClear();
			}
			if(Path_turn_flag)
			{
				if(Turn(TU_CW)){
					MotorOutputPIDClear();
					Path_turn_flag=0;Path_now++;
					break;
				}
				break;
			}
			FollowLineRememberLineClear();
			FollowLinePIDCallBack(FORTURNSPEED);
			break;
		}
		case 'T':
		{
			if(sensor[4]&&(Path_turn_flag==0))
			{
				Path_turn_flag=1;
				MotorOutputPIDClear();
			}
			if(Path_turn_flag)
			{
				if(Turn(TU_TB)){
					MotorOutputPIDClear();
					Path_turn_flag=0;Path_now++;
					break;
				}
				break;
			}
			FollowLineRememberLineClear();
			FollowLinePIDCallBack(FORTURNSPEED);
			break;
		}
	}
}
