/**
 * @file rotary_encoder.h
 * @brief TODO: Write a brief description of this file
 *
 * TODO: Write a detailed description of this file
 *
 * @date Created on: Jul 22, 2025
 * @author Dionisie Stratulat
 */
#ifndef INC_ROTARY_ENCODER_H_
#define INC_ROTARY_ENCODER_H_

#include <stdbool.h>
#include <stdint.h>

extern bool CLK_LastState; // Declared in rotary_encoder.c

typedef struct RotaryEncoder {
	bool CLKLastState;
} RotaryEncoder;

#endif /* INC_ROTARY_ENCODER_H_ */
