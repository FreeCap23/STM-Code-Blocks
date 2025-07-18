/**
 * @file spi_helper.c
 * @brief Implementation of SPI helper functions for register communication with R/W bit support.
 */

#include "spi_helper.h"

void spi_helper_init(SPI_Helper_t *helper, GPIO_TypeDef *cs_port, uint16_t cs_pin,
                     SPI_HandleTypeDef *hspi, uint8_t rw_bit_pos)
{
    helper->CS_Port = cs_port;
    helper->CS_Pin = cs_pin;
    helper->hspi = hspi;
    helper->RW_Bit_Pos = rw_bit_pos;
}

uint8_t spi_helper_read_register(SPI_Helper_t *helper, uint8_t reg_address)
{
    uint8_t tx[2] = {0}, rx[2] = {0};

    // Construct 16-bit frame: address with R/W bit set
    uint16_t cmd = ((uint16_t)reg_address << 8);
    cmd |= (1U << helper->RW_Bit_Pos);  // Set R/W = 1 for read

    tx[0] = (cmd >> 8) & 0xFF;
    tx[1] = cmd & 0xFF;

    HAL_GPIO_WritePin(helper->CS_Port, helper->CS_Pin, GPIO_PIN_RESET);
    HAL_SPI_TransmitReceive(helper->hspi, tx, rx, 2, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(helper->CS_Port, helper->CS_Pin, GPIO_PIN_SET);

    return rx[1];  // Data is returned in the second byte
}

int spi_helper_write_register(SPI_Helper_t *helper, uint8_t reg_address, uint8_t data)
{
    uint8_t tx[2] = {0}, rx[2] = {0};

    // Construct 16-bit frame: address with R/W bit cleared, followed by data
    uint16_t cmd = ((uint16_t)reg_address << 8);
    cmd &= ~(1U << helper->RW_Bit_Pos);  // Set R/W = 0 for write

    tx[0] = (cmd >> 8) & 0xFF;
    tx[1] = data;

    HAL_GPIO_WritePin(helper->CS_Port, helper->CS_Pin, GPIO_PIN_RESET);
    HAL_SPI_TransmitReceive(helper->hspi, tx, rx, 2, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(helper->CS_Port, helper->CS_Pin, GPIO_PIN_SET);

    // Read back and verify
    uint8_t read_back = spi_helper_read_register(helper, reg_address);
    return (read_back == data) ? 0 : 1;
}
