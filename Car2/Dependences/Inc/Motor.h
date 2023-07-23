#ifndef _MOTOR_H_
#define _MOTOR_H_

#include "Encoder.h"
#include "GrayScaler.h"

// 电机转向，反转改为-1
#define M_DIRL (1)
#define M_DIRR (1)

void Motor_Init(void);
void SetMotorOutput(int16_t pwmL, int16_t pwmR);//死区600左右

#endif
