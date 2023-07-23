#include "Task4.h"

Task4_t stage4, last_stage4;

void Mission4Handler(void) {
    switch(stage4) {
        case Turn1_4th:
            // stage initiate
            if(stage4 != last_stage4) {
                last_stage4 = stage4;

                // initiate todo
                FollowLineClearLineCount();
				turn_flag = CONTINUE;
            }

            // loop
            FirstTurn();

            // end condition
            if(1) {
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
            if(FollowLineForLengthCallBack(21,37000)) {
                // end todo
                SetMotorOutput(0, 0);

                stage4 ++;
            }
            break;

        case SendCar2StartMessage_4th:
            // stage initiate
            if(stage4 != last_stage4) {
                last_stage4 = stage4;

                // initiate todo
                Intercom_mystate = Intercom_Wait;
            }   

            // loop

            // end condition
            if(1) {
                // end todo

                stage4 ++;
            }
            break;

        case WaitForCar2Start_4th:
            // stage initiate
            if(stage4 != last_stage4) {
                last_stage4 = stage4;

                // initiate todo

            }

            // loop

            // end condition
            if(Intercom_yourstate == Intercom_Busy) {
                // end todo

                stage4 ++;
            }
            break;

        case WaitForCar2Stop_4th:
            // stage initiate
            if(stage4 != last_stage4) {
                last_stage4 = stage4;

                // initiate todo

            }

            // loop

            // end condition
            if(Intercom_yourstate == Intercom_Wait) {
                // end todo
                Intercom_mystate = Intercom_Busy;

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

        case Back_4th:
            // stage initiate
            if(stage4 != last_stage4) {
                last_stage4 = stage4;

                // initiate todo
                FollowLineClearLineCount();
            }

            // loop
            FollowLinePIDCallBack(-21);

            // end condition
            if(1) {
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

                stage4 ++;
            }
            break;

        case FollowLine2AndCar2Continue_4th:
            // stage initiate
            if(stage4 != last_stage4) {
                last_stage4 = stage4;

                // initiate todo
                FollowLineClearLineCount();
                MissionWait_ms(500);
            }

            // loop
            MissionWait_msCallBack();
            if(mission_wait_count == 0) Intercom_mystate = Intercom_Wait;
            FollowLinePIDCallBack(21);

            // end condition
            if(line_count >= 1) {
                // end todo
                SetMotorOutput(0, 0);

                stage4 ++;
            }
            break;

    }
}
