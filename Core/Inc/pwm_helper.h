/**
 * @file pwm_helper.h
 * @brief Helper functions for generating PWM signals
 *
 * @date Created on: Jul 16, 2025
 * @author Dionisie Stratulat
 */
#ifndef INC_PWM_HELPER_H_
#define INC_PWM_HELPER_H_

#include <stdint.h>

/**
 * @addtogroup helper_functions
 * @{
 * @defgroup PWM
 * @brief Functions for generating PWM signals
 * @{
 */
/**
 * @brief Selects the correct Capture/Compare Register (CCR) pointer based on the timer channel.
 *
 * Given a timer handle and a specific channel (TIM_CHANNEL_1 to TIM_CHANNEL_4),
 * this function returns a pointer to the corresponding CCR register (CCR1–CCR4).
 *
 * @param htim     Pointer to a TIM_HandleTypeDef structure that contains
 *                 the configuration information for the specified timer.
 * @param channel  Timer channel identifier (e.g., TIM_CHANNEL_1).
 * @returns Pointer to the selected CCR register, or NULL if the channel is invalid.
 */
static inline volatile uint32_t* _chooseCCR(TIM_HandleTypeDef *htim, uint32_t channel) {
  switch (channel) {
  case TIM_CHANNEL_1:
    return &htim->Instance->CCR1;
  case TIM_CHANNEL_2:
    return &htim->Instance->CCR2;
  case TIM_CHANNEL_3:
    return &htim->Instance->CCR3;
  case TIM_CHANNEL_4:
    return &htim->Instance->CCR4;
  default:
    return NULL;
  }
}

/**
 * @brief Writes a raw PWM compare value to the selected timer channel.
 *
 * This function limits the compare value to the auto-reload register (ARR)
 * value and writes it to the appropriate CCR register to control the PWM duty cycle.
 *
 * @param htim           Pointer to a TIM_HandleTypeDef structure.
 * @param channel        Timer channel identifier (e.g., TIM_CHANNEL_1).
 * @param compare_value  Raw PWM compare value (clipped to ARR).
 */
inline void analogWrite(TIM_HandleTypeDef *htim, uint32_t channel, uint16_t compare_value) {
  if (compare_value > htim->Instance->ARR)
    compare_value = htim->Instance->ARR;

  volatile uint32_t* CCR = _chooseCCR(htim, channel);
  *CCR = compare_value;
}

/**
 * @brief Writes a PWM duty cycle percentage to the selected timer channel.
 *
 * Converts a percentage value (0–100%) into a raw compare value based on the
 * current auto-reload register (ARR) and writes it to the corresponding CCR register.
 *
 * @param htim        Pointer to a TIM_HandleTypeDef structure.
 * @param channel     Timer channel identifier (e.g., TIM_CHANNEL_1).
 * @param duty_cycle  Duty cycle in percent (0–100); values above 100 are clamped to 100.
 */
inline void analogWritePercent(TIM_HandleTypeDef *htim, uint32_t channel, uint8_t duty_cycle) {
  if (duty_cycle > 100)
    duty_cycle = 100;

  volatile uint32_t* CCR = _chooseCCR(htim, channel);
  *CCR = ((float)duty_cycle / 100.0f) * htim->Instance->ARR;
}

/**
 * @}
 * @}
 */

#endif /* INC_PWM_HELPER_H_ */
