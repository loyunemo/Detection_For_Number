#ifndef _TASK3_H_
#define _TASK3_H_

// macro include

typedef enum{ 
    Turn1_3rd = 0,
    WaitForOpenMV_3rd,
    FollowLine1_3rd,
    Turn2_3rd,
    FollowLine2_3rd,
    WaitForMedicineOut_3rd,
    Back_3rd,
    Turn3_3rd,
    FollowLine3_3rd,
    Turn4_3rd,
    FollowLine4_3rd,
} Task3_t;

void Task3Handler(void);

extern Task3_t stage, last_stage

#endif
