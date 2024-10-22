/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#define BUT1_Pin GPIO_PIN_13
#define BUT1_GPIO_Port GPIOC
#define BUT2_Pin GPIO_PIN_14
#define BUT2_GPIO_Port GPIOC
#define BUT3_Pin GPIO_PIN_15
#define BUT3_GPIO_Port GPIOC
#define red1_Pin GPIO_PIN_1
#define red1_GPIO_Port GPIOA
#define green1_Pin GPIO_PIN_2
#define green1_GPIO_Port GPIOA
#define yellow1_Pin GPIO_PIN_3
#define yellow1_GPIO_Port GPIOA
#define red2_Pin GPIO_PIN_4
#define red2_GPIO_Port GPIOA
#define green2_Pin GPIO_PIN_5
#define green2_GPIO_Port GPIOA
#define yellow2_Pin GPIO_PIN_6
#define yellow2_GPIO_Port GPIOA
#define red3_Pin GPIO_PIN_7
#define red3_GPIO_Port GPIOA
#define SEG0_Pin GPIO_PIN_0
#define SEG0_GPIO_Port GPIOB
#define SEG1_Pin GPIO_PIN_1
#define SEG1_GPIO_Port GPIOB
#define SEG2_Pin GPIO_PIN_2
#define SEG2_GPIO_Port GPIOB
#define EN1_Pin GPIO_PIN_12
#define EN1_GPIO_Port GPIOB
#define EN2_Pin GPIO_PIN_13
#define EN2_GPIO_Port GPIOB
#define EN3_Pin GPIO_PIN_14
#define EN3_GPIO_Port GPIOB
#define EN4_Pin GPIO_PIN_15
#define EN4_GPIO_Port GPIOB
#define green3_Pin GPIO_PIN_8
#define green3_GPIO_Port GPIOA
#define yellow3_Pin GPIO_PIN_9
#define yellow3_GPIO_Port GPIOA
#define red4_Pin GPIO_PIN_10
#define red4_GPIO_Port GPIOA
#define green4_Pin GPIO_PIN_11
#define green4_GPIO_Port GPIOA
#define yellow4_Pin GPIO_PIN_12
#define yellow4_GPIO_Port GPIOA
#define SEG3_Pin GPIO_PIN_3
#define SEG3_GPIO_Port GPIOB
#define SEG4_Pin GPIO_PIN_4
#define SEG4_GPIO_Port GPIOB
#define SEG5_Pin GPIO_PIN_5
#define SEG5_GPIO_Port GPIOB
#define SEG6_Pin GPIO_PIN_6
#define SEG6_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
