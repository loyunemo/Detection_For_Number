/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Debug_LED_Pin GPIO_PIN_13
#define Debug_LED_GPIO_Port GPIOC
#define Encoder1_A_Pin GPIO_PIN_0
#define Encoder1_A_GPIO_Port GPIOA
#define Encoder1_B_Pin GPIO_PIN_1
#define Encoder1_B_GPIO_Port GPIOA
#define Medicine_Box_Pin GPIO_PIN_2
#define Medicine_Box_GPIO_Port GPIOA
#define Debug_Rightbutton_Pin GPIO_PIN_3
#define Debug_Rightbutton_GPIO_Port GPIOA
#define Debug_Leftbutton_Pin GPIO_PIN_4
#define Debug_Leftbutton_GPIO_Port GPIOA
#define Encoder2_A_Pin GPIO_PIN_6
#define Encoder2_A_GPIO_Port GPIOA
#define Encoder2_B_Pin GPIO_PIN_7
#define Encoder2_B_GPIO_Port GPIOA
#define LED_R_Pin GPIO_PIN_0
#define LED_R_GPIO_Port GPIOB
#define LED_G_Pin GPIO_PIN_1
#define LED_G_GPIO_Port GPIOB
#define tmp_OUTPUT_Pin GPIO_PIN_2
#define tmp_OUTPUT_GPIO_Port GPIOB
#define Signal_IN_Pin GPIO_PIN_12
#define Signal_IN_GPIO_Port GPIOB
#define Signal_OUT_Pin GPIO_PIN_13
#define Signal_OUT_GPIO_Port GPIOB
#define Sensor1_Pin GPIO_PIN_14
#define Sensor1_GPIO_Port GPIOB
#define Sensor2_Pin GPIO_PIN_15
#define Sensor2_GPIO_Port GPIOB
#define Sensor3_Pin GPIO_PIN_8
#define Sensor3_GPIO_Port GPIOA
#define Sensor4_Pin GPIO_PIN_11
#define Sensor4_GPIO_Port GPIOA
#define Sensor5_Pin GPIO_PIN_12
#define Sensor5_GPIO_Port GPIOA
#define Motor_IN1_Pin GPIO_PIN_15
#define Motor_IN1_GPIO_Port GPIOA
#define Motor_IN2_Pin GPIO_PIN_3
#define Motor_IN2_GPIO_Port GPIOB
#define Motor_IN3_Pin GPIO_PIN_4
#define Motor_IN3_GPIO_Port GPIOB
#define Motor_IN4_Pin GPIO_PIN_5
#define Motor_IN4_GPIO_Port GPIOB
#define Sensor6_Pin GPIO_PIN_8
#define Sensor6_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
