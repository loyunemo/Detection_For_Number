/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-07-06 10:52:17
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-07-12 12:15:22
 * @FilePath: \Explorerss\Tasks\Inc\Control.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _CONTROL_H_
#define _CONTROL_H_

#define DEBUG_BUTTON   // 调试模式，必须按下左侧调试按钮才能开始，比赛时注释掉

#include "Encoder.h"
#include "LED.h"
#include "GrayScaler.h"
#include "Motor.h"
#include "mpu6050.h"
#include "oled.h"
#include "MedicineBox.h"
#include "PID.h"
#include "intercom.h"

#include "followline.h"
#include "TaskManager.h"
#include "Functions.h"

#include "stm32f1xx_it.h"
#include "tim.h"
#include "main.h"
#include "usart.h"
#include "gpio.h"

// 先出发的id是1，第二辆是2
#define ID 1
typedef struct button{
    uint8_t button;
    uint8_t last_button;
}BUTTON;

void ControlInit(void);
void Control(void);

extern uint8_t debug_stop;
extern BUTTON left_button, right_botton;
extern uint64_t fps;

#endif
