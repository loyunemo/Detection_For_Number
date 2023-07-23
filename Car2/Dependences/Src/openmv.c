#include "openmv.h"

uint8_t openmv_wait_switch; // 0代表获取目标房间门牌，1~8代表寻找数字n,
uint8_t openmv_mission_flag;
uint8_t openmv_rxbuffer[OPENMV_RXBUF_MAXLEN];

void OpenMv_Init(void)
{
	openmv_wait_switch = 0;
	openmv_mission_flag = 0;
}
	
// void OpenMvCallBack(void)
// {
// 	HAL_UART_Receive_DMA(&OPENMV_UART, openmv_rxbuffer, 1);
// }

void OpenMVGetTarRoom(void){
	openmv_wait_switch = 9;
	HAL_UART_Transmit(&OPENMV_UART, &openmv_wait_switch, 1, 0xff);
	HAL_UART_Receive_IT(&OPENMV_UART, openmv_rxbuffer, 1);
}

void OpenMVGetMap(void){
	openmv_wait_switch = mission.target_number;
	HAL_UART_Transmit(&OPENMV_UART, &openmv_wait_switch, 1, 0xff);
	HAL_UART_Receive_IT(&OPENMV_UART, openmv_rxbuffer, 1);
}

void OpenMVGetDirection(void){
	openmv_wait_switch = 0x10 + mission.target_number;
	HAL_UART_Transmit(&OPENMV_UART, &openmv_wait_switch, 1, 0xff);
	HAL_UART_Receive_IT(&OPENMV_UART, openmv_rxbuffer, 1);
}

// 串口中断回调函数
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if(huart == &huart1){
		if(openmv_wait_switch == 9){
			mission.target_number = openmv_rxbuffer[0];
			if(mission.target_number==1||mission.target_number==2)
			{
				mission.location_number=mission.target_number;
			}
			openmv_wait_switch = 0;
		}
		else if(openmv_wait_switch > 0 && openmv_wait_switch < 9){
			mission.location_number = openmv_rxbuffer[0];
			openmv_wait_switch = 0;
		}
		else if(openmv_wait_switch > 0x10 && openmv_wait_switch < 0x19){
			mission.turn_direction = openmv_rxbuffer[0];
			openmv_wait_switch = 0;
		}
	}
}


