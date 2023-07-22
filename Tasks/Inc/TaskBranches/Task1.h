#ifndef _TASK1_H_
#define _TASK1_H_

#include "TaskManager.h"

typedef enum{
	Turn1_1st= 0,
	FollowLine1_1st,
	WaitForMedicineOut_1st,
	Back_1st,
	Turn2_1st,
	FollowLine2_1st,
}Mission_Stage_1st;

void Mission1Handler(void);

extern Mission_Stage_1st stage1, last_stage1;

#endif
