#include "intercom.h"

uint8_t Intercom_mystate;
uint8_t Intercom_yourstate;
uint8_t Intercom_connect;

void Intercom_Init(void)
{
	IntercomCallBack();
	if(Intercom_yourstate==Intercom_Busy)
	{
		Intercom_connect=Intercom_Busy;
	}
	else{
		Intercom_connect=Intercom_Wait;
	}
}

void IntercomCallBack(void)
{
	HAL_GPIO_WritePin(Signal_OUT_GPIO_Port,Signal_OUT_Pin,Intercom_mystate);
	Intercom_yourstate=HAL_GPIO_ReadPin(Signal_IN_GPIO_Port,Signal_IN_Pin);
}
