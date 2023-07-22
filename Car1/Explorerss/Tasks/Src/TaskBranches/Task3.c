#include "Task3.h"

void Turn2_3rdCall(void);
void Turn4_3rdCall(void);

Mission_Stage_3rd stage3, last_stage3;

void Mission3Handler(void){
    switch (stage3) {
        case Turn1_3rd:
            if(stage3 != last_stage3){
                last_stage3 = stage3;
                // stageInit
            }
            FirstTurn();
            break;
        case WaitForOpenMV_3rd:
            if(stage3 != last_stage3){
                last_stage3 = stage3;
                // stageInit
            }
            OpenMVGetDirection();
            stage3++;
            break;
        case FollowLine1_3rd:
            if(stage3 != last_stage3){
                last_stage3 = stage3;
                // stageInit
            }
            Knockline(21, 1);
            break;
        case Turn2_3rd:
            if(stage3 != last_stage3){
                last_stage3 = stage3;
                // stageInit
            }
            Turn2_3rdCall();
            break;
        case FollowLine2_3rd:
            if(stage3 != last_stage3){
                last_stage3 = stage3;
                // stageInit
            }
            Knockline(21, 1);
            break;
        case WaitForMedicineOut_3rd:
            if(stage3 != last_stage3){
                last_stage3 = stage3;
                // stageInit
            }
            MedicineWaitOut();
            break;
        case Back_3rd:
            if(stage3 != last_stage3){
                last_stage3 = stage3;
                // stageInit
            }
            Knockline(-21, 1);
            break;
        case Turn3_3rd:
            if(stage3 != last_stage3){
                last_stage3 = stage3;
                // stageInit
            }
            Turn2_3rdCall(); // Turn3和Turn2一样
            break;
        case FollowLine3_3rd:
            if(stage3 != last_stage3){
                last_stage3 = stage3;
                // stageInit
            }
            Knockline(21, 1);
            break;
        case Turn4_3rd:
            if(stage3 != last_stage3){
                last_stage3 = stage3;
                // stageInit
            }
            Turn4_3rdCall();
            break;
        case FollowLine4_3rd:
            if(stage3 != last_stage3){
                last_stage3 = stage3;
                // stageInit
            }
            Knockline(21, 3);
            break;
    }
}

void Turn2_3rdCall(void){
	if(mission.turn_direction % 2){ // 如果房间位号为奇数
		if(Turn(TU_CC, 1) == END){
			FollowLineClearLineCount();
            stage1++;
		}
	}
	else {
		if(Turn(TU_CW, 1) == END){ // 如果房间位号为偶数
			FollowLineClearLineCount();
            stage1++;
		}
	}
}

void Turn4_3rdCall(void){
    if(mission.location_number % 2){ // 如果房间位号为奇数
		if(Turn(TU_CW, 1) == END){
			FollowLineClearLineCount();
            stage1++;
		}
	}
	else {
		if(Turn(TU_CC, 1) == END){ // 如果房间位号为偶数
			FollowLineClearLineCount();
            stage1++;
		}
	}
}
