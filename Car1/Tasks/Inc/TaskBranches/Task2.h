#ifndef _TASK2_H_
#define _TASK2_H_

#include "TaskManager.h"

typedef enum{
	Turn1_2nd = 0,
	FollowLine1_2nd,
	WaitForMedicineOut_2nd,
	Back_2nd,
	Turn2_2nd,
	FollowLine2_2nd
}Mission_Stage_2nd;

void Mission2Handler(void);

extern Mission_Stage_2nd stage2, last_stage2;

#endif
