/**
 * @file flash_helper.c
 * @brief TODO: Write a brief description of this file
 *
 * TODO: Write a detailed description of this file
 *
 * @date Created on: Jul 17, 2025
 * @author Dionisie Stratulat
 */

#include "flash_helper.h"
#include "main.h"
#include <string.h>


HAL_StatusTypeDef FLASH_HELPER_Init(void) {
    // Unlock the Flash to enable the flash control register access
    return HAL_FLASH_Unlock();
}

#if defined(FLASH_TYPE_PAGE) && !defined(FLASH_TYPE_SECTOR)
HAL_StatusTypeDef FLASH_HELPER_ErasePage(uint32_t page) {
    FLASH_EraseInitTypeDef erase_init;
    uint32_t page_error;

	erase_init.TypeErase = FLASH_TYPEERASE_PAGES;
	erase_init.PageAddress = FLASH_BASE + (page * FLASH_PAGE_SIZE);
	erase_init.NbPages = 1;
    erase_init.VoltageRange = VOLTAGE_RANGE_3;
    return HAL_FLASHEx_Erase(&erase_init, &page_error);
}
#elif defined(FLASH_TYPE_SECTOR) && !defined(FLASH_TYPE_PAGE)
HAL_StatusTypeDef FLASH_HELPER_EraseSector(uint32_t sector) {
    FLASH_EraseInitTypeDef erase_init;
    uint32_t sector_error;

    erase_init.TypeErase = FLASH_TYPEERASE_SECTORS;
	erase_init.Sector = sector;
	erase_init.NbSectors = 1;
#ifndef STM32H7
    erase_init.VoltageRange = VOLTAGE_RANGE_2;
#endif
    return HAL_FLASHEx_Erase(&erase_init, &sector_error);
}
#endif

HAL_StatusTypeDef FLASH_HELPER_Write(uint32_t address, uint8_t *data, uint32_t size) {
    HAL_StatusTypeDef status = HAL_OK;
    uint32_t *src = (uint32_t*)data;
    uint32_t *dst = (uint32_t*)address;
    uint32_t words = (size + 3) / 4; // Convert bytes to words (rounding up)

    // Check if address and size are properly aligned (H7 requirements may differ)
    #if defined(STM32H7)
    if ((address % 32) != 0 || (size % 32) != 0) { // H7 uses 256-bit flash words (32 bytes)
        return HAL_ERROR;
    }
    #else
    if ((address % 8) != 0 || (size % 8) != 0) { // Standard STM32 64-bit requirement
        return HAL_ERROR;
    }
    #endif

    for (uint32_t i = 0; i < words; ) {
        #if defined(STM32H7)
        // H7 uses FLASHWORD programming (256 bits/32 bytes)
        status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD, (uint32_t)&dst[i], (uint32_t)&src[i]);
        i += 8; // Advance 8 words (32 bytes)
        #else
        // Standard double word (64-bit) programming
        uint64_t value = ((uint64_t)src[i+1] << 32) | src[i];
        status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, (uint32_t)&dst[i], value);
        i += 2; // Advance 2 words (8 bytes)
        #endif

        if (status != HAL_OK) {
            break;
        }
    }

    return status;
}

HAL_StatusTypeDef FLASH_HELPER_Read(uint32_t address, uint8_t *data, uint32_t size) {
    memcpy(data, (void*)address, size);
    return HAL_OK;
}

bool FLASH_HELPER_IsEmpty(uint32_t address, uint32_t size) {
    uint8_t *ptr = (uint8_t*)address;

    for (uint32_t i = 0; i < size; i++) {
        if (ptr[i] != 0xFF) { // Flash erased state is 0xFF
            return false;
        }
    }

    return true;
}
