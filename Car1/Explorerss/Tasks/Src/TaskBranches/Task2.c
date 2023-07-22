#include "Task2.h"

Mission_Stage_2nd stage2, last_stage2;

void Mission2Handler(void){
    switch(stage2){
        case Turn1_2nd:
        	if(stage2 != last_stage2){
				last_stage2 = stage2;
				// stageInit
			}
            FirstTurn();
            break;
        case FollowLine1_2nd:
        	if(stage2 != last_stage2){
				last_stage2 = stage2;
				// stageInit
			}
            Knockline(21, 0);
            break;
        case WaitForMedicineOut_2nd:
        	if(stage2 != last_stage2){
				last_stage2 = stage2;
				// stageInit
			}
            MedicineWaitOut();
            break;
        case Back_2nd:
        	if(stage2 != last_stage2){
				last_stage2 = stage2;
				// stageInit
			}
            Knockline(-21, 1);
            break;
        case Turn2_2nd:
        	if(stage2 != last_stage2){
				last_stage2 = stage2;
				// stageInit
			}
            FirstTurn();
            break;
        case FollowLine2_2nd:
        	if(stage2 != last_stage2){
				last_stage2 = stage2;
				// stageInit
			}
            Knockline(21, 2);
            break;
    }
}

