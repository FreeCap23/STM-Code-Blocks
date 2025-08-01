/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32h7xx_hal.h"

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
#define RotaryEncoder_CLK_Pin GPIO_PIN_13
#define RotaryEncoder_CLK_GPIO_Port GPIOC
#define RotaryEncoder_CLK_EXTI_IRQn EXTI15_10_IRQn
#define RotaryEncoder_DT_Pin GPIO_PIN_2
#define RotaryEncoder_DT_GPIO_Port GPIOC
#define DRV8705_CS_Pin GPIO_PIN_4
#define DRV8705_CS_GPIO_Port GPIOA
#define INT1_ADXL345_Pin GPIO_PIN_2
#define INT1_ADXL345_GPIO_Port GPIOB
#define CS_ADXL345_Pin GPIO_PIN_7
#define CS_ADXL345_GPIO_Port GPIOC
#define RotaryEncoder_SW_Pin GPIO_PIN_4
#define RotaryEncoder_SW_GPIO_Port GPIOD
#define RotaryEncoder_SW_EXTI_IRQn EXTI4_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
