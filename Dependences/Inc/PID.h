#ifndef __PID_H__
#define __PID_H__

#include <math.h>

typedef struct _PIDTypeDef
{
	float Kp;
	float Ki;
	float Kd;
	float last_error;
	float sum;
	float ref;
	float up_bound;
	float down_bound;
}PIDTypeDef;

void PID_Init(PIDTypeDef *hpid);
void PID_DeInit(PIDTypeDef *hpid);
float PID_Compute(PIDTypeDef *hpid,float ref,float input);
float PID_ComputeFixed(PIDTypeDef *hpid,float input);

#endif
