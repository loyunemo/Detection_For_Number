#ifndef _COMMUNICATION_H_
#define _COMMUNICATION_H_

#include "gpio.h"
#include "Control.h"

extern uint16_t count_communication;

enum State{
    WAIT,
    WORK
};

extern enum State state;

void CommunicationInit(void);
void Work(void);
void WaitAndSendMessage(void);

#endif
