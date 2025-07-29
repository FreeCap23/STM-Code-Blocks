/**
 * @file adxl345.c
 * @brief TODO: Write a brief description of this file
 *
 * TODO: Write a detailed description of this file
 *
 * @date Created on: Jul 28, 2025
 * @author Dionisie Stratulat
 */

#include "adxl345.h"

void adxl345_write_register(SPI_HandleTypeDef *hspi, uint8_t address, uint8_t value) {
	uint8_t tx[2] = {0};
	tx[0] = address & ~0x80; // Make sure R/W bit is reset
	tx[1] = value;
	HAL_GPIO_WritePin(CS_ADXL345_GPIO_Port, CS_ADXL345_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(hspi, tx, 2, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(CS_ADXL345_GPIO_Port, CS_ADXL345_Pin, GPIO_PIN_SET);
}

uint8_t adxl345_read_register(SPI_HandleTypeDef *hspi, uint8_t address) {
	uint8_t tx = address | 0x80; // Set R/W bit
	uint8_t rx = 0;
	HAL_GPIO_WritePin(CS_ADXL345_GPIO_Port, CS_ADXL345_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(hspi, &tx, 1, HAL_MAX_DELAY);
	HAL_SPI_Receive(hspi, &rx, 1, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(CS_ADXL345_GPIO_Port, CS_ADXL345_Pin, GPIO_PIN_SET);
	return rx;
}
