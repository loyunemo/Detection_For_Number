#include "Motor.h"

int16_t mL_out, mR_out;

void MotorInit(void){
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
    HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_2);
}

void SetMotorOutput(int16_t pwmL, int16_t pwmR){
    if(pwmL > 0){
        if(M_DIRL == 1){
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
        }
        else{
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
        }
        __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_1, pwmL);
    }
    else{
        if(M_DIRL == 1){
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
        }
        else{
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
        }
        __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_1, -pwmL);
    }

    if(pwmR > 0){
        if(M_DIRL == 1){
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
        }
        else{
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
        }
        __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_2, pwmR);
    }
    else{
        if(M_DIRL == 1){
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
        }
        else{
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
        }
        __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_2, -pwmR);
    }
}

