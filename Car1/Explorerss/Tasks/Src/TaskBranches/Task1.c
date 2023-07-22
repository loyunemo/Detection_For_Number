#include "Task1.h"

Mission_Stage_1st stage1, last_stage1;

void Mission1Handler(void){
	switch(stage1){
		case Turn1_1st: 
			if(stage1 != last_stage1){
				last_stage1 = stage1;
				// stageInit
			}
			FirstTurn();
			break;
		case FollowLine1_1st: 
			if(stage1 != last_stage1){
				last_stage1 = stage1;
				// stageInit
			}
			Knockline(21, 1);
			break;
		case WaitForMedicineOut_1st:
			if(stage1 != last_stage1){
				last_stage1 = stage1;
				// stageInit
			}
			MedicineWaitOut();
			break;
		case Back_1st:
			if(stage1 != last_stage1){
				last_stage1 = stage1;
				// stageInit
			}
			Knockline(-21, 1);
			break;
		case Turn2_1st:
			if(stage1 != last_stage1){
				last_stage1 = stage1;
				// stageInit
			}
            FirstTurn();
		case FollowLine2_1st:
			if(stage1 != last_stage1){
				last_stage1 = stage1;
				// stageInit
			}
			Knockline(21, 1);
	}
}



