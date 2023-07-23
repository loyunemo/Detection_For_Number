#include "Task3.h"

Mission_Stage_3rd stage3, last_stage3;

void Mission3Handler(void){
    switch (stage3) {
        case Turn1_3rd:
            // stage initiate
			if(stage3 != last_stage3){
				last_stage3 = stage3;

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

				stage3 ++;
			}
			break;
            
        case WaitForOpenMV_3rd:
            // stage initiate
            if(stage3 != last_stage3){
                last_stage3 = stage3;

                // initiate todo
                OpenMVGetDirection();
            }

            // loop
            
            // end conditions
            if(1){
                // end todo

                stage3++;
            }
            break;

        case FollowLine1_3rd:
            // stage initiate
            if(stage3 != last_stage3){
                last_stage3 = stage3;

                // initiate todo
                FollowLineClearLineCount();
            }

            // loop
            FollowLinePIDCallBack(21);

            // end conditions
            if(line_count >= 1){
                // end todo
                SetMotorOutput(0, 0);

                stage3 ++;
            }
            break;

        case Turn2_3rd:
            // stage intiate
            if(stage3 != last_stage3){
                last_stage3 = stage3;

                // stageInit
                turn_flag = CONTINUE;
                FollowLineClearLineCount();
            }

            // loop
            if(mission.turn_direction % 2) turn_flag = ForwardTurn(TU_CC);
            else turn_flag = ForwardTurn(TU_CW);

            // end conditions
            if(turn_flag == END){
                // end todo
                SetMotorOutput(0, 0);
                
                stage3 ++;
            }
            break;

        case FollowLine2_3rd:
            // stage intiate
            if(stage3 != last_stage3){
                last_stage3 = stage3;

                // initiate todo
                FollowLineClearLineCount();
            }

            // loop
            FollowLinePIDCallBack(21);

            // end conditions
            if(line_count >= 1){
                // end todo
                SetMotorOutput(0, 0);

                stage3 ++;
            }
            break;

        case WaitForMedicineOut_3rd:
            // initiate stage
            if(stage3 != last_stage3){
                last_stage3 = stage3;
                
                // initiate todo

            }

            // loop

            // end conditions
            if(!loaded){
                // end todo

                stage3 ++;
            }
            break;

        case Back_3rd:
            // stage initiate
            if(stage3 != last_stage3){
                last_stage3 = stage3;

                // initiate todo
                FollowLineClearLineCount();
            }

            // loop
            FollowLinePIDCallBack(-21);

            // end conditions
            if(line_count >= 1){
                // end todo
                SetMotorOutput(0, 0);

                stage3 ++;
            }
            break;

        case Turn3_3rd:
            // stage initate
            if(stage3 != last_stage3){
                last_stage3 = stage3;

                // initiate todo
                turn_flag = CONTINUE;
                FollowLineClearLineCount();
            }

            // loop
            if(mission.turn_direction % 2) turn_flag = ForwardTurn(TU_CC);
            else turn_flag = ForwardTurn(TU_CW);

            // end conditions
            if(turn_flag == END){
                //end todo
                SetMotorOutput(0, 0);

                stage3 ++;
            }
            break;

        case FollowLine3_3rd:
            // stage initiate
            if(stage3 != last_stage3){
                last_stage3 = stage3;

                // initiate todo
                FollowLineClearLineCount();
            }

            // loop
            FollowLinePIDCallBack(21);

            // end conditions
            if(line_count >=1){
                // end todo
                SetMotorOutput(0, 0);

                stage3 ++;
            }
            break;

        case Turn4_3rd:
            // stage initiate
            if(stage3 != last_stage3){
                last_stage3 = stage3;

                // initiate todo
                turn_flag = CONTINUE;
                FollowLineClearLineCount();
            }

            // loop
            if(mission.turn_direction % 2) turn_flag = ForwardTurn(TU_CW);
            else turn_flag = ForwardTurn(TU_CC);

            // end conditions
            if(turn_flag == END){
                // end todo
                SetMotorOutput(0, 0);

                stage3 ++;;
            }
            break;

        case FollowLine4_3rd:
            // stage initiate
            if(stage3 != last_stage3){
                last_stage3 = stage3;

                // initiate todo
                FollowLineClearLineCount();
            }

            // loop
            FollowLinePIDCallBack(21);

            // end conditions
            if(line_count >= 3){
                // end to do
                SetMotorOutput(0, 0);

                stage3 ++;
            }
            break;
    }
}
