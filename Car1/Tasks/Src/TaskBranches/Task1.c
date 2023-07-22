#include "Task1.h"

Mission_Stage_1st stage1, last_stage1;

void Mission1Handler(void){
	switch(stage1){
		case Turn1_1st: 
			// stage initiate
			if(stage1 != last_stage1){
				last_stage1 = stage1;

				// initiate todo 
				FollowLineClearLineCount();
				turn_flag = CONTINUE;
			}

			// loop
			FirstTurn();

			// end condition
			if(turn_flag == END){
				// end todo 
				FollowLineClearLineCount();
				SetMotorOutput(0, 0);

				stage1 ++;
			}
			break;

		case FollowLine1_1st: 
			if(stage1 != last_stage1){
				last_stage1 = stage1;
				
				// initiate todo
				FollowLineClearLineCount();
			}

			// loop
			FollowLinePIDCallBack(21);

			// end conditions
			if(line_count >= 1){
				// end todo
				FollowLineClearLineCount();
				SetMotorOutput(0, 0);

				stage1 ++;
			}
			break;

		case WaitForMedicineOut_1st:
			// stage initiate
			if(stage1 != last_stage1){
				last_stage1 = stage1;
				// initiate todo

			}
			// loop

			if(!loaded) {
				// end todo

				stage1++;
			}
			break;

		case Back_1st:
			// stage initiate
			if(stage1 != last_stage1){
				last_stage1 = stage1;

				// initiate todo
				FollowLineClearLineCount();
			}
			
			// loop
			FollowLinePIDCallBack(-21);
			
			// end conditions
			if(line_count >= 1){
				//end todo
				FollowLineClearLineCount();
				SetMotorOutput(0, 0);

				stage1 ++;
			}
			break;

		case Turn2_1st:
			// stage initiate
			if(stage1 != last_stage1){
				last_stage1 = stage1;

				// initate todo
				turn_flag = CONTINUE;
				FollowLineClearLineCount();
			}

			// loop
            FirstTurn();

			// end conditions
			if(turn_flag == END){
				// end todo
				FollowLineClearLineCount();
				SetMotorOutput(0, 0);

				stage1 ++;
			}
			break;

		case FollowLine2_1st:
			// stage initiate
			if(stage1 != last_stage1){
				last_stage1 = stage1;

				// stageInit

			}

			// loop
			FollowLinePIDCallBack(21);

			// end conditions
			if(line_count >= 1){
				// end todo
				FollowLineClearLineCount();
				SetMotorOutput(0, 0);

				stage1 ++;
			}
	}
}



