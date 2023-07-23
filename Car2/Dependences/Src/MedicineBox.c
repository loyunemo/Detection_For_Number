#include "MedicineBox.h"

uint8_t loaded;

void MedicineBox_Init(void){
    loaded = 0;
}

void MedicineBoxCallBack(void){
    loaded = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2); 
}

