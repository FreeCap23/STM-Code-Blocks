/**
 * @file spi_helper.h
 * @brief SPI helper module for register-based communication over SPI with configurable R/W bit.
 *
 * This module provides basic read and write access to SPI-based devices
 * using 16-bit frame formats, with customizable R/W bit position.
 *
 * @date Created on: Jul 18, 2025
 * @author Dionisie Stratulat
 */
#ifndef INC_SPI_HELPER_H_
#define INC_SPI_HELPER_H_

#include "main.h"
#include <stdint.h>

/**
 * @brief SPI helper configuration structure.
 */
typedef struct {
    GPIO_TypeDef *CS_Port;      /**< GPIO port for Chip Select (CS) */
    uint16_t CS_Pin;            /**< GPIO pin for Chip Select (CS) */
    SPI_HandleTypeDef *hspi;    /**< SPI handle (HAL) */
    uint8_t RW_Bit_Pos;         /**< Bit position for the R/W flag in the 16-bit SPI frame */
} SPI_Helper_t;

/**
 * @brief Initializes the SPI helper configuration.
 *
 * @param helper Pointer to SPI_Helper_t structure to initialize.
 * @param cs_port GPIO port of CS pin.
 * @param cs_pin GPIO pin number of CS.
 * @param hspi Pointer to the SPI HAL handle.
 * @param rw_bit_pos Position of the read/write bit (e.g., 14 for DRV8705).
 */
void spi_helper_init(SPI_Helper_t *helper, GPIO_TypeDef *cs_port, uint16_t cs_pin,
                     SPI_HandleTypeDef *hspi, uint8_t rw_bit_pos);

/**
 * @brief Reads a register via SPI.
 *
 * @param helper Pointer to initialized SPI_Helper_t structure.
 * @param reg_address 6–8 bit register address (depending on device).
 * @return uint8_t Value read from the register.
 */
uint8_t spi_helper_read_register(SPI_Helper_t *helper, uint8_t reg_address);

/**
 * @brief Writes a value to a register and verifies it by reading back.
 *
 * @param helper Pointer to initialized SPI_Helper_t structure.
 * @param reg_address 6–8 bit register address (depending on device).
 * @param data Value to write.
 * @return int 0 if write succeeded (verified), 1 if verification failed.
 */
int spi_helper_write_register(SPI_Helper_t *helper, uint8_t reg_address, uint8_t data);

#endif /* INC_SPI_HELPER_H_ */
