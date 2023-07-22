/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-07-17 01:06:30
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-07-17 08:25:25
 * @FilePath: \Explorerss\Tasks\Inc\followline.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __FOLLOWLINE_H__
#define __FOLLOWLINE_H__

#include "GrayScaler.h"
#include "Motor.h"
#include "PID.h"
#include "oled.h"
#include "Encoder.h"
#include "Functions.h"

//Kp:0.82 Ki=0 Kd=0.08
//Kp:0.32 Ki=0.075/0.088 Kd=0.012
#define FL_Kp 0.5f
#define FL_Ki 0.0f
#define FL_Kd 0.0f

#define END 1
#define CONTINUE 0

extern uint8_t sensors[6];

extern uint8_t line_count, last_line_count;

void FollowLinePID_Init(void);
uint8_t  FollowLinePIDCallBack(int MotorSpeed);//当数到新线时返回1
void FollowLineClearLineCount(void);
uint8_t FollowLineForLengthCallBack(int MotorSpeed,uint16_t encoder_len);

#endif
