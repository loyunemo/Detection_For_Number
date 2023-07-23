#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "PID.h"
#include "Motor.h"
#include "GrayScaler.h"
#include "FollowLine.h"
#include <math.h>
#include <stdlib.h>

//MotorPID

/*
Kp=1.8 Ki=0.8 Kd=0.1
Kp=1.75 Ki=1.15 Kd=0.5
Kp=2 Ki=0.3 Kd=0.1
*/

#define MT_Kp 1.90f
#define MT_Ki 0.17f
#define MT_Kd 0.25f
#define MT_up 1000
#define MT_down -1000

void SetMotorOutputPID(int16_t Lspeed,int16_t Rspeed);
uint8_t SetMotorOutputEncoder(int16_t encoderL,int16_t encoderR,int16_t time_ms);
void MotorOutputPIDClear(void);

//Turn

#define TU_CW -1//Clockwise
#define TU_CC 1 //Countclock
#define TU_TB 0 //Turnback

#define FULLTURN 22000	//反向的所需编码器计数
#define HALFTURN 9000		//转向所需编码器计数

uint8_t Turn(int8_t Dir);
uint8_t ForwardTurn(int8_t Dir);

//Path

#define SPEED 25
#define FORTURNSPEED 21
#define LENGTH 300

extern uint8_t Path[20];
extern uint8_t Path_now;
extern uint8_t Path_act;
extern uint8_t Path_on;

void GoPath(void);

//STAGE

#define STAGE(INIT,LOOP,ENDCON,ENDTODO)\
{\
	static uint8_t init_flag=1;\
	if(init_flag)\
	{\
		init_flag=0;\
		{INIT}\
	}\
	if(ENDCON)\
	{\
		{ENDTODO}\
		init_flag=1;\
	}\
	{LOOP}\
}

#endif
