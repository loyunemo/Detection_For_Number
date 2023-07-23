#include "Task4.h"

Task4_t stage4, last_stage4;

void Mission4Handler(void) {
    switch(stage4) {
        case OpenLoopForward_4th:
            // stage initiate
            if(stage4 != last_stage4) {
                last_stage4 = stage4;

                // initiate todo
                MissionWait_ms(1000);
            }

            // loop
            MissionWait_msCallBack();
            FollowLinePIDCallBack(21);
            // end condition
            if(mission_wait_count == 0) {
                // end todo
                SetMotorOutput(0, 0);

                stage4 ++;
            }
            break;

        case WaitForCar1Message_4th:
            // stage initiate
            if(stage4 != last_stage4) {
                last_stage4 = stage4;

                // initiate todo

            }

            // loop

            // end condition
            if(Intercom_yourstate == Intercom_Wait) {
                // end todo

                stage4 ++;
            }
            break;

        case Back1_4th:
            // stage initiate
            if(stage4 != last_stage4) {
                last_stage4 = stage4;

                // initiate todo
                FollowLineClearLineCount();
            }

            // loop
            FollowLinePIDCallBack(-21);

            // end condition
            if(line_count == 1) {
                // end todo
                SetMotorOutput(0, 0);

                stage4 ++;
            }
            break;

        case Turn1_4th:
            // stage initiate
            if(stage4 != last_stage4) {
                last_stage4 = stage4;

                // initiate todo
                turn_flag == CONTINUE;
                FollowLineClearLineCount();
            }

            // loop
            FirstTurn();

            // end condition
            if(turn_flag == END) {
                // end todo
                SetMotorOutput(0, 0);

                stage4 ++;
            }
            break;

        case FollowLine1_4th:
            // stage initiate
            if(stage4 != last_stage4) {
                last_stage4 = stage4;

                // initiate todo
                FollowLineClearLineCount();
            }

            // loop
            FollowLinePIDCallBack(21);

            // end condition
            if(line_count == 1) {
                // end todo
                SetMotorOutput(0, 0);

                stage4 ++;
            }
            break;

        case WaitForMedicineOut_4th:
            // stage initiate
            if(stage4 != last_stage4) {
                last_stage4 = stage4;

                // initiate todo

            }

            // loop

            // end condition
            if(!loaded) {
                // end todo

                stage4 ++;
            }
            break;

        case Back2_4th:
            // stage initiate
            if(stage4 != last_stage4) {
                last_stage4 = stage4;

                // initiate todo
                FollowLineClearLineCount();
            }

            // loop
            FollowLinePIDCallBack(-21);

            // end condition
            if(line_count == 1) {
                // end todo
                SetMotorOutput(0, 0);

                stage4 ++;
            }
            break;

        case Turn2_4th:
            // stage initiate
            if(stage4 != last_stage4) {
                last_stage4 = stage4;

                // initiate todo
                turn_flag = CONTINUE;
                FollowLineClearLineCount();
            }

            // loop
            FirstTurn();

            // end condition
            if(turn_flag == END) {
                // end todo
                SetMotorOutput(0, 0);

                stage4 ++;
            }
            break;

        case FollowLine2_4th:
            // stage initiate
            if(stage4 != last_stage4) {
                last_stage4 = stage4;

                // initiate todo
                FollowLineClearLineCount();
            }

            // loop

            // end condition
            if(line_count == 1) {
                // end todo
                SetMotorOutput(0, 0);

                stage4 ++;
            }
            break;

    }
}
