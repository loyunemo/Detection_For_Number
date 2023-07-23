#ifndef _TASK4_H_
#define _TASK4_H_

// macro include
#include "TaskManager.h"

typedef enum{ 
    Turn1_4th = 0,
    FollowLine1_4th,
    SendCar2StartMessage_4th,
    WaitForCar2Start_4th,
    WaitForCar2Stop_4th,
    WaitForMedicineOut_4th,
    Back_4th,
    Turn2_4th,
    FollowLine2AndCar2Continue_4th,
} Task4_t;

void Mission4Handler(void);

extern Task4_t stage4, last_stage4;

#endif
