#ifndef _TASK4_H_
#define _TASK4_H_

// macro include
#include "TaskManager.h"

typedef enum{ 
    OpenLoopForward_4th = 0,
    WaitForCar1Message_4th,
    Back1_4th,
    Turn1_4th,
    FollowLine1_4th,
    WaitForMedicineOut_4th,
    Back2_4th,
    Turn2_4th,
    FollowLine2_4th,
} Task4_t;

void Mission4Handler(void);

extern Task4_t stage4, last_stage4;

#endif
