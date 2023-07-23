#include "TaskManager.h"

/**************************macro functions*********************************/
void Mission0Handler(void);
void MissionWait_ms(uint32_t n);
void MissionWait_msCallBack(void);
void EnquireVehicleNum(void);
void OpenMVWaitForMission(void);
void JudgeBranch(void); 		// 判断进入哪个分支

// void 


/*************************macro variable***********************************/
Mission_t mission;
Mission_Stage_ALL stage0, last_stage0;

Mission_t mission;
uint8_t mission_wait_flag;
uint32_t mission_wait_count;
uint8_t turn_flag;

void TaskManager_Init(void)
{
	turn_flag = 0;
	mission_wait_flag = 0;
	mission.mission_number = 0;
	stage0 = WaitForCar1Message;
	last_stage0 = WaitForCar1Message;
}

// call in Control()
void TaskManagerCallBack(void)
{
	switch(mission.mission_number){
		case 0: Mission0Handler(); break;
		case 4: Mission4Handler(); break;
		case 5: Mission5Handler(); break;
	}
}

void Mission0Handler(void){
	switch(stage0){
		case WaitForCar1Message: 
			// stage initiate		
			if(stage0 != last_stage0){
				last_stage0 = stage0;

				// initiate todo
				Intercom_mystate = Intercom_Wait;
			}

			// loop
			MissionWait_msCallBack();

			// end conditions
			if(Intercom_yourstate == Intercom_Wait){
				// end todo 

				stage0 ++;
			}
			break;

		case WaitForOpenMV: 
			// stage initiate
			if(stage0 != last_stage0){
				last_stage0 = stage0;
				OpenMVWaitForMission();
			}

			// loop

			//end conditions
			if(!openmv_wait_switch) {
				// end todo

				stage0++;
			}
			break;

		case WaitForMedicineIn: 
			// stageInit
			if(stage0 != last_stage0){
				last_stage0 = stage0;

				// initiate todo 
			}

			// loop

			// end conditions
			if(loaded){
				// end todo

				stage0++;
			}
			break;
			
		case OpenLoopForward: 
			// stage initiate
			if(stage0 != last_stage0){
				last_stage0 = stage0;
				
				// initiate todo
			}

			// loop

			// end conditions
			if(SetMotorOutputEncoder(23000,23000,1000)) {
				// end todo
				MotorOutputPIDClear();

				stage0++;
			}
			break;

		case OpenMVStartSearching: 
			// stage initiate
			if(stage0 != last_stage0){
				last_stage0 = stage0;
				
				// initiate todo
				OpenMVGetMap();
			}

			// loop

			// end conditions
			if(1) {
				// end todo

				stage0++;
			}
			break;

		case FollowLine: 
			// stage initiate	
			if(stage0 != last_stage0){
				last_stage0 = stage0;

				// initiate todo
				FollowLineClearLineCount();
			}

			// loop
			FollowLinePIDCallBack(21);

			// end conditions
			if(line_count == 2){
				// end todo
				SetMotorOutput(0, 0);

				stage0 ++;
			}
			break;		

		case ChooseBranch:
			// stage initate
			if(stage0 != last_stage0){
				last_stage0 = stage0;

				// initiate todo
				JudgeBranch();
			}

			// loop

			// end conditions
			if(1) {
				// end todo

				stage0++;
			}
			break;
	}
	
}

void MissionWait_ms(uint32_t n){
	mission_wait_count = n;
}

void MissionWait_msCallBack(void){
	if(mission_wait_count > 0){
		mission_wait_count --;
	}
}

void OpenMVWaitForMission(void){
	OpenMVGetTarRoom();
}

void JudgeBranch(void){ // 判断进入哪个分支
	if(openmv_wait_switch == 0) mission.mission_number = 4;
	else mission.mission_number = 5;
}

void FirstTurn(void){
	if(mission.location_number % 2){ // 如果房间位号为奇数
		turn_flag = ForwardTurn(TU_CC);
	}
	else {
		turn_flag = ForwardTurn(TU_CW);
	}
}
