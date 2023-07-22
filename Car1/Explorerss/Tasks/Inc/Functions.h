#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "PID.h"
#include "Motor.h"
#include "GrayScaler.h"
#include "FollowLine.h"

//MotorPID

#define MT_Kp 1.90f
#define MT_Ki 0.17f
#define MT_Kd 0.25f
#define MT_up 1000
#define MT_down -1000

void SetMotorOutputPID(int16_t Lspeed,int16_t Rspeed);
void MotorOutputPIDClear(void);

//Turn

#define TU_CW -1//Clockwise
#define TU_CC 1 //Countclock
#define TU_TB 0 //Turnback

#define TURNSPEED 12

uint8_t Turn(int8_t Dir,uint8_t count);

//Path

#define SPEED 20
#define LENGTH 300

extern uint8_t Path[20];
extern uint8_t Path_now;
extern uint8_t Path_act;
extern uint8_t Path_on;

void GoPath(void);

#endif
