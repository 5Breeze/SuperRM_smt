/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32l0xx_hal.h"

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
#define C_Pin GPIO_PIN_9
#define C_GPIO_Port GPIOB
#define DAH_Pin GPIO_PIN_14
#define DAH_GPIO_Port GPIOC
#define DIT_Pin GPIO_PIN_15
#define DIT_GPIO_Port GPIOC
#define B_Pin GPIO_PIN_0
#define B_GPIO_Port GPIOA
#define RX_Pin GPIO_PIN_1
#define RX_GPIO_Port GPIOA
#define A_Pin GPIO_PIN_4
#define A_GPIO_Port GPIOA
#define RFRX_Pin GPIO_PIN_7
#define RFRX_GPIO_Port GPIOA
#define RFTX_Pin GPIO_PIN_9
#define RFTX_GPIO_Port GPIOA
#define BEEP_Pin GPIO_PIN_10
#define BEEP_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
