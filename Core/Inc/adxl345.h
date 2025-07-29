/**
 * @file adxl345.h
 * @brief TODO: Write a brief description of this file
 *
 * TODO: Write a detailed description of this file
 *
 * @date Created on: Jul 28, 2025
 * @author Dionisie Stratulat
 */
#ifndef INC_ADXL345_H_
#define INC_ADXL345_H_

#include "stm32h7xx.h"
#include "main.h"

void adxl345_write_register(SPI_HandleTypeDef *hspi, uint8_t address, uint8_t value);

uint8_t adxl345_read_register(SPI_HandleTypeDef *hspi, uint8_t address);

#endif /* INC_ADXL345_H_ */
