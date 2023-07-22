/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-07-06 17:57:21
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-07-10 19:43:29
 * @FilePath: \Explorerss\Dependences\Src\GrayScaler.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "GrayScaler.h"
#include "oled.h"

uint8_t sensor[6] = {0}, all_sensors;
uint8_t sensor_count=0,ex_sensor_count=0;
static GPIO_TypeDef *sensor_port[6] = {
    GPIOB,
    GPIOB,
    GPIOA,
    GPIOA,
    GPIOA,
    GPIOB
};
static uint16_t sensor_pin[6] = {
    GPIO_PIN_14,
    GPIO_PIN_15,
    GPIO_PIN_8,
    GPIO_PIN_11,
    GPIO_PIN_12,
    GPIO_PIN_8
};

void GrayScalerCallBack(void){
    int i;
    all_sensors = 0x00;
		sensor_count=0;
    for(i=0;i<6;i++){
        sensor[i] = (HAL_GPIO_ReadPin(sensor_port[i], sensor_pin[i])==ONLINE);
        all_sensors += sensor[i] << i;
//        OLED_ShowNum(i*8+30, 5, sensor[i]);
    }
		for(i=0;i<4;i++)
		{
			sensor_count+=sensor[i];
		}
		ex_sensor_count=sensor[4]+sensor[5];
}

void GrayScaler_Init(void){

}