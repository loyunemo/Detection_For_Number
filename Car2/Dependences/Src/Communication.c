#include "Communication.h"

enum State state;
uint16_t count_communication, flag_communication;

void CommunicationInit(void){
    count_communication = 0;
    flag_communication = 0;
    switch(ID){
        case 1: HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
                state = WORK;
                break;
        case 2: HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
                state = WAIT;
                break;
    }
}

void Work(void){
    state = WORK;
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
}

void WaitAndSendMessage(void){
    state = WAIT;
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
    flag_communication = 1;
}

void Communication_CallBack(void){
    if(flag_communication == 1){
        if(count_communication < WAIT_TIME) count_communication++;
    }
    else count_communication = 0;

    if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12) == 0 && flag_communication == 0 && count_communication >= WAIT_TIME){
        Work();
    }
}
