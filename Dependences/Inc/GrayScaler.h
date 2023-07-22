/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-07-06 17:56:39
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-07-17 01:21:55
 * @FilePath: \Explorerss\Dependences\Inc\GrayScaler.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _GRAYSCALER_H_
#define _GRAYSCALER_H_

#include "gpio.h"

#define ONLINE GPIO_PIN_SET

extern uint8_t sensor[6], all_sensors;
extern uint8_t sensor_count,ex_sensor_count;

void GrayScaler_Init(void);
void GrayScalerCallBack(void);

#endif
