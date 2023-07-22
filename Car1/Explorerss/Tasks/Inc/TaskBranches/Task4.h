#ifndef _TASK4_H_
#define _TASK4_H_

#include "TaskManager.h"

typedef enum{
	Turn1_4th = 0,
	WaitForMedicine_4th,
}Mission_Stage_4th;

void Mission2Handler(void);

extern Mission_Stage_4th stage4, last_stage4;

#endif
