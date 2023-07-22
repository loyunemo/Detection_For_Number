#include "Motor.h"

int16_t mL_out, mR_out;

void MotorInit(void){
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
    HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_2);
}

void SetMotorOutput(int16_t pwmL, int16_t pwmR){
    if(pwmL > 0){
        if(M_DIRL == 1){
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, SET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
        }
        else{
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, RESET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
        }
        __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_1, pwmL);
    }
    else{
        if(M_DIRL == 1){
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, RESET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
        }
        else{
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, SET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
        }
        __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_1, -pwmL);
    }

    if(pwmR > 0){
        if(M_DIRL == 1){
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
        }
        else{
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
        }
        __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_2, pwmR);
    }
    else{
        if(M_DIRL == 1){
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
        }
        else{
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
        }
        __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_2, -pwmR);
    }
}

