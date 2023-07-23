#include "PID.h"

void PID_Init(PIDTypeDef *hpid)
{
	hpid->last_error=0;
	hpid->sum=0;
	hpid->up_bound=10000;
	hpid->down_bound=-10000;
}

void PID_DeInit(PIDTypeDef *hpid)
{
	hpid->last_error=0;
	hpid->sum=0;
}

float PID_Compute(PIDTypeDef *hpid,float ref,float input)
{
	hpid->ref=ref;
	float error =hpid->ref-input;
	hpid->sum+=error;
	float output=hpid->Kp*error+hpid->Ki*hpid->sum+hpid->Kd*(error-hpid->last_error);
	hpid->last_error=error;
	if(output<hpid->down_bound)output=hpid->down_bound;
	if(output>hpid->up_bound)output=hpid->up_bound;
	return output;
}

float PID_ComputeFixed(PIDTypeDef *hpid,float input)
{
	return PID_Compute(hpid,hpid->ref,input);
}
