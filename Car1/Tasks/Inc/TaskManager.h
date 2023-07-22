#ifndef __TASKMANAGER_H__
#define __TASKMANAGER_H__

#include "MedicineBox.h"
#include "LED.h"
#include "openmv.h"
#include "Functions.h"
#include "followline.h"
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task4.h"
#include "Task5.h"
#include "followline.h"

/*
房间方位号，对应数组下标
|  8    |--------------------|  10   |
|              5      6              |
|       |-------      -------|       |
|  7    |      |      |      |  9    |
               |      |
       --------        ---------
               3       4        
       --------        ---------
               |       |  
               |       |
	   --------        ----------
			   1       2
	   --------        ----------
	           |       |
*/
/******************************** User's Types ********************************/
typedef struct{
	uint8_t vehicle_number; // 几辆车
	uint8_t mission_number; // 第几个测试点(1/2/3/4/5)
	uint8_t target_number; // 去几号房间
	uint8_t location_number; // 去几号位
	uint8_t turn_direction; // 仅远端有用，最后路口1左转2右转
}Mission_t;

typedef enum{
	Wait10ms = 0,
	EnquireCarNum, // 查询小车数量
	WaitForOpenMV,
	WaitForMedicineIn,
	OpenMVStartSearching,
	FollowLine,
	ChooseBranch,
}Mission_Stage_ALL;

/*****************************User's Functions *********************************/
void TaskManager_Init(void);
void TaskManagerCallBack(void);	
void FirstTurn(void);

/***************************Extern Variables**************************/
extern Mission_t mission;
extern uint8_t room_sequence[6];
extern Mission_Stage_ALL stage0, last_stage0;
extern uint8_t mission_wait_flag;
extern uint32_t mission_wait_count;
extern uint8_t turn_flag;

#endif
