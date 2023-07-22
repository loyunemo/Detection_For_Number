#ifndef __OPENMV_H__
#define __OPENMV_H__

#include "Taskmanager.h"
#include "usart.h"

#define OPENMV_UART huart1
#define OPENMV_RXBUF_MAXLEN 10

void OpenMv_Init(void);
// void OpenMvCallBack(void);
void OpenMVGetTarRoom(void);
void OpenMVGetMap(void);
void OpenMVGetDirection(void);

extern uint8_t openmv_mission_flag;
extern uint8_t openmv_wait_switch; // 0代表获取目标房间门牌，1~8代表寻找数字n,

#endif
