/**
 * @file us_timer.h
 * @brief TODO: Write a brief description of this file
 *
 * TODO: Write a detailed description of this file
 *
 * @date Created on: Aug 4, 2025
 * @author Dionisie Stratulat
 */
#ifndef INC_US_TIMER_H_
#define INC_US_TIMER_H_

#include "stm32h7xx_hal.h" // Change this if needed

/**
 * @brief Returns the time elapsed in us
 *
 * @param *htim Pointer to the Timer handle configured to run at 1 MHz
 * @return Time in us
 */
uint32_t get_tick_us(TIM_HandleTypeDef *htim);

/**
 * @brief Delays code execution by the given value in us
 * @warning This function delays by the exact amount only 99.6% of the time. The rest of the time it is +- 1us.
 *
 * @param *htim Pointer to the Timer handle configured to run at 1 MHz
 * @param delay How many us to delay
 */
void delay_us(TIM_HandleTypeDef *htim, uint32_t delay);

#endif /* INC_US_TIMER_H_ */
