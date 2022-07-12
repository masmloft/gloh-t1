/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "stm32g0xx_hal.h"

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
#define GLO_BUTTON1_Pin GPIO_PIN_13
#define GLO_BUTTON1_GPIO_Port GPIOC
#define GLO_TEMPR1_Pin GPIO_PIN_6
#define GLO_TEMPR1_GPIO_Port GPIOA
#define GLO_TEMPR2_Pin GPIO_PIN_7
#define GLO_TEMPR2_GPIO_Port GPIOA
#define GLO_LED2_Pin GPIO_PIN_0
#define GLO_LED2_GPIO_Port GPIOB
#define GLO_LED3_Pin GPIO_PIN_1
#define GLO_LED3_GPIO_Port GPIOB
#define GLO_LED4_Pin GPIO_PIN_6
#define GLO_LED4_GPIO_Port GPIOC
#define GLO_LED1_Pin GPIO_PIN_7
#define GLO_LED1_GPIO_Port GPIOC
#define GLO_POLEV2_2_Pin GPIO_PIN_11
#define GLO_POLEV2_2_GPIO_Port GPIOA
#define GLO_POLEV2_Pin GPIO_PIN_12
#define GLO_POLEV2_GPIO_Port GPIOA
#define GLO_POLEV1_Pin GPIO_PIN_15
#define GLO_POLEV1_GPIO_Port GPIOA
#define GLO_EH_POWER_Pin GPIO_PIN_8
#define GLO_EH_POWER_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
