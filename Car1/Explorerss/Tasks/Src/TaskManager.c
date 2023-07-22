#include "TaskManager.h"

/**************************macro functions*********************************/
void Mission0Handler(void);
void Mission1Handler(void);
void Mission2Handler(void);
void Mission3Handler(void);
void Mission4Handler(void);
void Mission5Handler(void);
void MissionWait_ms(uint32_t n);
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

void TaskManager_Init(void)
{
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
			if(stage0 != last_stage0){
				last_stage0 = stage0;
				// stageInit
			}
			MissionWait_ms(10);
			break;
		case EnquireCarNum: 
			if(stage0 != last_stage0){
				last_stage0 = stage0;
				// stageInit
			}
			EnquireVehicleNum();  
			break;
		case WaitForOpenMV: 
			if(stage0 != last_stage0){
				last_stage0 = stage0;
				// stageInit
				OpenMVWaitForMission();
			}
			break;
		case WaitForMedicineIn: 
			if(stage0 != last_stage0){
				last_stage0 = stage0;
				// stageInit
			}
			MedicineWaitIn();
			break;
		case OpenMVStartSearching: 
			if(stage0 != last_stage0){
				last_stage0 = stage0;
				// stageInit
			}
			OpenMVGetMap();
			stage0++;
			break;
		case FollowLine: 	
			if(stage0 != last_stage0){
				last_stage0 = stage0;
				// stageInit
			}
			Knockline(21, 0);
			break;					
		case ChooseBranch:
			if(stage0 != last_stage0){
				last_stage0 = stage0;
				// stageInit
			}
			JudgeBranch();
			break;
	}
	
}

void MissionWait_ms(uint32_t n){
	if(!mission_wait_flag) mission_wait_count = n;
	if(--n){
		switch(mission.mission_number){
			case 0: stage0++; break;
			case 1: stage1++; break;
			case 2: stage2++; break;
			case 3: stage3++; break;
			case 4: stage4++; break;
			case 5: stage5++; break;
		}
	}
}

void EnquireVehicleNum(void){
	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13) == GPIO_PIN_SET)
		mission.vehicle_number = 1; // 若读到高电平通讯输出则断言是单车任务
	else mission.vehicle_number = 2;// 若读到低电平通讯输出则断言是多车任务
	stage0++;
}

void OpenMVWaitForMission(void){
	OpenMVGetTarRoom();
	if(!openmv_wait_switch) stage0++;
}

void MedicineWaitIn(void){
	if(loaded){
		switch(mission.mission_number){
			case 0: stage0++; break;
			case 1: stage1++; break;
			case 2: stage2++; break;
			case 3: stage3++; break;
			case 4: stage4++; break;
			case 5: stage5++; break;
		}
	}
}

void MedicineWaitOut(void){
	if(!loaded){
		switch(mission.mission_number){
			case 0: stage0++; break;
			case 1: stage1++; break;
			case 2: stage2++; break;
			case 3: stage3++; break;
			case 4: stage4++; break;
			case 5: stage5++; break;
		}
	}
}

void Knockline(int16_t speed, int16_t num){
	FollowLinePIDCallBack(speed);
	if(num == 0){
		if(line_count != last_line_count && !openmv_wait_switch){
			SetMotorOutput(0, 0);
			FollowLineClearLineCount();
			switch(mission.mission_number){
				case 0: stage0++; break;
				case 1: stage1++; break;
				case 2: stage2++; break;
				case 3: stage3++; break;
				case 4: stage4++; break;
				case 5: stage5++; break;
			}
		}
	}
	else {
		if(line_count >= num){
			SetMotorOutput(0, 0);
			FollowLineClearLineCount();
			switch(mission.mission_number){
				case 0: stage0++; break;
				case 1: stage1++; break;
				case 2: stage2++; break;
				case 3: stage3++; break;
				case 4: stage4++; break;
				case 5: stage5++; break;
			}
		}
	}
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
	stage0++;
}

void FirstTurn(void){
	if(mission.location_number % 2){ // 如果房间位号为奇数
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
