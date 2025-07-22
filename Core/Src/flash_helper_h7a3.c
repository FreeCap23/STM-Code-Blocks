/**
 * @file flash_helper_h7a3.c
 * @brief Implementation of Flash memory utility functions for STM32H7A3 using HAL.
 * @date Created on: Jul 21, 2025
 * @author Dionisie Stratulat
 */

#include <string.h>
#include "flash_helper_h7a3.h"

#define FLASH_BASE_ADDRESS    0x08000000U     /**< Start of Flash memory */
#define FLASH_BANK_NUMBER     FLASH_BANK_1    /**< Default to Bank 1 for single bank devices */

/**
 * @brief Computes the sector number based on an address.
 *
 * @param address Flash memory address
 * @return Sector number
 */
static uint32_t GetSector(uint32_t address) {
    return (address - FLASH_BASE_ADDRESS) / FLASH_SECTOR_SIZE;
}

HAL_StatusTypeDef Flash_Erase(uint32_t address) {
    HAL_StatusTypeDef status;
    FLASH_EraseInitTypeDef eraseInit;
    uint32_t sectorError = 0;

    HAL_FLASH_Unlock();

    eraseInit.TypeErase = FLASH_TYPEERASE_SECTORS;
    eraseInit.Banks = FLASH_BANK_NUMBER;
    eraseInit.Sector = GetSector(address);
    eraseInit.NbSectors = 1;
//    eraseInit.VoltageRange = VOLTAGE_RANGE_3;

    status = HAL_FLASHEx_Erase(&eraseInit, &sectorError);

    HAL_FLASH_Lock();
    return status;
}

HAL_StatusTypeDef Flash_Write(uint32_t address, uint64_t* data, size_t length_in_bytes) {
    HAL_StatusTypeDef status = HAL_OK;

    if (address % 16 != 0 || ((uintptr_t)data) % 4 != 0) {
        return HAL_ERROR; // Address must be 128-bit aligned; data must be 32-bit aligned
    }

    HAL_FLASH_Unlock();

    size_t total_words = length_in_bytes / 16 + ((length_in_bytes % 16) ? 1 : 0);
    uint8_t temp[16];

    for (size_t i = 0; i < total_words; i++) {
        // Prepare 16 bytes to write (pad with 0xFF if needed)
        memset(temp, 0xFF, sizeof(temp));
        size_t remaining = length_in_bytes - i * 16;
        size_t copy_len = (remaining >= 16) ? 16 : remaining;
        memcpy(temp, (uint8_t*)data + i * 16, copy_len);

        status = HAL_FLASH_Program(
            FLASH_TYPEPROGRAM_FLASHWORD,
            address + i * 16,
            (uint32_t)(uintptr_t)temp
        );

        if (status != HAL_OK) {
            break;
        }
    }

    HAL_FLASH_Lock();
    return status;
}

void Flash_Read(uint32_t address, uint8_t* data, size_t length) {
    for (size_t i = 0; i < length; i++) {
        data[i] = *((__IO uint8_t*)(address + i));
    }
}
