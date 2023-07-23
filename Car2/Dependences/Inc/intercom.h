#ifndef __INTERCOM_H__
#define __INTERCOM_H__

#include "gpio.h"

#define Intercom_Busy 1
#define Intercom_Wait 0

extern uint8_t Intercom_mystate;
extern uint8_t Intercom_yourstate;
extern uint8_t Intercom_connect;

void Intercom_Init(void);
void IntercomCallBack(void);

#endif
