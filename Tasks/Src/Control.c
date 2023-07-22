/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-07-06 10:52:08
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-07-17 08:29:16
 * @FilePath: \Explorerss\Tasks\Src\Control.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "Control.h"

uint8_t debug_stop;
BUTTON left_button, right_button;
extern PIDTypeDef hpid_lmotor, hpid_rmotor;

uint64_t fps=0;

/*
Kp=1.8 Ki=0.8 Kd=0.1
Kp=1.75 Ki=1.15 Kd=0.5
Kp=2 Ki=0.3 Kd=0.1
*/

int16_t Loutput1,Routput1;

void ControlInit(void){
	// MPU6050_Init(&hi2c2);
    GrayScalerCallBack();
    EncoderInit();
    LED_Init();
    MotorInit();
    PID_DeInit(&hpid_lmotor);
    PID_DeInit(&hpid_rmotor);
    OLED_Init(&hi2c2);
    OLED_CLS();
	Intercom_Init();
	TaskManager_Init();
    FollowLinePID_Init();
	Path_on=1;
    HAL_TIM_Base_Start_IT(&htim4);

    debug_stop = left_button.button = left_button.last_button = right_button.button = right_button.last_button = 0;
#ifdef DEBUG_BUTTON
    debug_stop = 1;
#endif
}

void Control(void){
#ifdef DEBUG_BUTTON
    left_button.last_button = left_button.button;
    right_button.last_button = right_button.button;
    left_button.button = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);
    right_button.button = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3);
    if(!left_button.last_button && left_button.button) debug_stop = 0;
    else if(!right_button.last_button && right_button.button) debug_stop = 1;
#endif
    if(!debug_stop){
        if(right_button.button);
			fps++;
        EncoderCallBack();
        GrayScalerCallBack();
		IntercomCallBack();
        MedicineBoxCallBack();

		TaskManagerCallBack();
        
    }
    else{
        EncoderCallBack();
        GrayScalerCallBack();
        SetMotorOutput(0, 0);
        Ignite(R);
    } 
}
