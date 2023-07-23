#include "Encoder.h"

int16_t encoderL_1ms, encoderR_1ms, encoderL_10ms, encoderR_10ms;
static int16_t encoder_count, encoderL_10ms_tmp, encoderR_10ms_tmp;

void Encoder_Init(void){
    encoderL_1ms = encoderR_1ms = encoderL_10ms = encoderR_10ms = 0;
    encoder_count = encoderL_10ms_tmp = encoderR_10ms_tmp = 0;
    HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
    HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
}

void Encoder_DeInit(void){
		encoderL_1ms = encoderR_1ms = encoderL_10ms = encoderR_10ms = 0;
    encoder_count = encoderL_10ms_tmp = encoderR_10ms_tmp = 0;
}

void EncoderCallBack(void){
    encoderL_1ms = E_LDIR * __HAL_TIM_GET_COUNTER(&htim3);
    encoderR_1ms = E_RDIR * __HAL_TIM_GET_COUNTER(&htim2);
    encoderL_10ms_tmp += E_LDIR * __HAL_TIM_GET_COUNTER(&htim3);
    encoderR_10ms_tmp += E_RDIR * __HAL_TIM_GET_COUNTER(&htim2);
	__HAL_TIM_SET_COUNTER(&htim3,0);  // ����������
	__HAL_TIM_SET_COUNTER(&htim2,0);  // ����������
    if(++encoder_count > 9) {
        encoder_count = 0;
        encoderL_10ms = encoderL_10ms_tmp;
        encoderR_10ms = encoderR_10ms_tmp;
				encoderL_10ms_tmp = 0;
				encoderR_10ms_tmp = 0;
    }
}

