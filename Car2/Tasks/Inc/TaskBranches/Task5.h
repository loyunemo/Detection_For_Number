#ifndef _TASK5_H_
#define _TASK5_H_

#include "TaskManager.h"

typedef enum{
	Turn1_5th = 0,
	WaitForMedicine_5th,
}Mission_Stage_5th;

void Mission5Handler();

extern Mission_Stage_5th stage5, last_stage5;

#endif
