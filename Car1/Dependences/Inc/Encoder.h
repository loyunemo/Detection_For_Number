/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-07-06 13:22:05
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-07-12 13:46:05
 * @FilePath: \Explorerss\Dependences\Inc\Encoder.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _ENCODER_H_
#define _ENCODER_H_

#include "tim.h"
#define WAIT_TIME 400 //(ms)
// 若需要反转则改为-1
#define E_LDIR (1)
#define E_RDIR (-1)

extern int16_t encoderL_1ms, encoderR_1ms, encoderL_10ms, encoderR_10ms;

void EncoderInit(void);
void EncoderCallBack(void);


#endif
