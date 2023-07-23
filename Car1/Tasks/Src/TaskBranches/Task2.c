#include "Task2.h"

Mission_Stage_2nd stage2, last_stage2;

void Mission2Handler(void){
    switch(stage2){
        case Turn1_2nd:
			// stage initiate
			if(stage2 != last_stage2){
				last_stage2 = stage2;

				// initiate todo 
				FollowLineClearLineCount();
				turn_flag = CONTINUE;
			}

			// loop
			FirstTurn();

			// end condition
			if(turn_flag == END){
				// end todo 
				SetMotorOutput(0, 0);

				stage2 ++;
			}
            break;

        case FollowLine1_2nd:
			// stage initiate
        	if(stage2 != last_stage2){
				last_stage2 = stage2;

				// initiate todo
				FollowLineClearLineCount();
			}

			// loop
            FollowLinePIDCallBack(21);

			// end conditions
			if(line_count >= 2){
				// end todo
				SetMotorOutput(0, 0);

				stage2 ++;
			}
            break;

        case WaitForMedicineOut_2nd:
			// stage initiate
        	if(stage2 != last_stage2){
				last_stage2 = stage2;
				// initiate todo

			}
            
			// loop

			// end conditions
			if(!loaded){
				// end todo

				stage2 ++;
			}
            break;

        case Back_2nd:
			// stage initiate
        	if(stage2 != last_stage2){
				last_stage2 = stage2;

				// initiate todo
				FollowLineClearLineCount();
			}

			// loop 
            FollowLinePIDCallBack(-21);

			// end conditions
			if(line_count >= 1){
				//end todo
				SetMotorOutput(0, 0);

				stage2 ++;
			}
            break;

        case Turn2_2nd:
			// stage initiate
        	if(stage2 != last_stage2){
				last_stage2 = stage2;

				// initiate todo
				turn_flag = CONTINUE;
				FollowLineClearLineCount();
			}

			// loop
            FirstTurn();

			// end conditions
			if(turn_flag){
				// end todo
				SetMotorOutput(0, 0);

				stage2 ++;
			}
            break;

        case FollowLine2_2nd:
			// stage initiate
        	if(stage2 != last_stage2){
				last_stage2 = stage2;

				// initiate todo

			}

			// loop
            FollowLinePIDCallBack(21);

            break;
    }
}

