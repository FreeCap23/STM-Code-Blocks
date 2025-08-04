/**
 * @file us_timer.c
 * @brief TODO: Write a brief description of this file
 *
 * TODO: Write a detailed description of this file
 *
 * @date Created on: Aug 4, 2025
 * @author Dionisie Stratulat
 */

#include "us_timer.h"

uint32_t get_tick_us(TIM_HandleTypeDef *htim) {
    return __HAL_TIM_GET_COUNTER(htim);
}

void delay_us(TIM_HandleTypeDef *htim, uint32_t delay) {
    uint32_t start = __HAL_TIM_GET_COUNTER(htim);
    while ((uint32_t)(__HAL_TIM_GET_COUNTER(htim) - start) < delay - 2);
}
