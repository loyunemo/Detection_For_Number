#include "TaskManager.h"

/**************************macro functions*********************************/
void Mission0Handler(void);
void Mission1Handler(void);
void Mission2Handler(void);
void Mission3Handler(void);
void Mission4Handler(void);
void Mission5Handler(void);
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
	stage0 = WaitForOpenMV;
	last_stage0 = EnquireCarNum;
}

// call in Control()
void TaskManagerCallBack(void)
{
	switch(mission.mission_number){
		case 0: Mission0Handler(); break;
		case 1: Mission1Handler(); break;
		case 2: Mission2Handler(); break;
		case 3: Mission3Handler(); break;
		case 4: Mission4Handler(); break;
		case 5: Mission5Handler(); break;
	}
}

void Mission0Handler(void){
	switch(stage0){
		case Wait10ms: 
			// stage initiate		
			if(stage0 != last_stage0){
				last_stage0 = stage0;

				// initiate todo
				MissionWait_ms(2000);
			}

			// loop
			MissionWait_msCallBack();

			// end conditions
			if(mission_wait_count == 0){
				// end todo 

				stage0 ++;
			}
			break;

		case EnquireCarNum: 
			// stage initiate
			if(stage0 != last_stage0){
				last_stage0 = stage0;
			}

			// loop
			EnquireVehicleNum();

			// end conditions
			if(1) {
				// end todo

				stage0++;  
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
			if(line_count != last_line_count && (!openmv_wait_switch || mission.target_number <= 2)){
				// end todo

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

void EnquireVehicleNum(void){
	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12) == GPIO_PIN_SET)
		mission.vehicle_number = 1; // 若读到高电平通讯输出则断言是单车任务
	else mission.vehicle_number = 2;// 若读到低电平通讯输出则断言是多车任务
}

void OpenMVWaitForMission(void){
	OpenMVGetTarRoom();
}

void JudgeBranch(void){ // 判断进入哪个分支
	if(mission.vehicle_number == 1){
		if(mission.mission_number <= 2){
			stage1 = Turn1_1st;
			mission.mission_number = 1;
		}
		else{
			if(line_count == 2){
				stage2 = Turn1_2nd;
				mission.mission_number = 2;
			}
			else {
				stage3 = Turn1_3rd;
				mission.mission_number = 3;
			}
		}
	}
	else{
		if(line_count == 2){
			stage4 = Turn1_4th;
			mission.mission_number = 4;
		}
		else {
			stage5 = Turn1_5th;
			mission.mission_number = 5;
		}
	}
}

void FirstTurn(void){
	if(mission.location_number % 2){ // 如果房间位号为奇数
		turn_flag = Turn(TU_CC, 1);
	}
	else {
		turn_flag = Turn(TU_CC, 1);
	}
}
