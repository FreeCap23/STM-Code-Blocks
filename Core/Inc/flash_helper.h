/**
 * @file flash_helper.h
 * @brief Flash memory helper for STM32 family
 *
 * This module provides helper functions for flash memory operations on STM32 devices.
 *
 * @note Before using this module, define either FLASH_TYPE_PAGE or FLASH_TYPE_SECTOR in your project settings.
 *
 * Example usage for STM32H7:
 * @code
 * // Initialize flash helper
 * FLASH_HELPER_Init();
 *
 * // Erase sector 7 (adjust sector number as needed)
 * FLASH_HELPER_Erase(7);
 *
 * // Prepare data - must be 32-byte aligned for H7
 * uint8_t data[32] = {0x01, 0x02, ...};
 *
 * // Write to flash (address must be 32-byte aligned)
 * FLASH_HELPER_Write(0x08080000, data, sizeof(data));
 *
 * // Read back data
 * uint8_t read_data[32];
 * FLASH_HELPER_Read(0x08080000, read_data, sizeof(read_data));
 *
 * // Verify if region is empty
 * if(FLASH_HELPER_IsEmpty(0x08080000, 32)) {
 *     // Flash region is empty (all 0xFF)
 * }
 * @endcode
 *
 * @date Created on: Jul 17, 2025
 * @author Dionisie Stratulat
 */

#ifndef FLASH_HELPER_H
#define FLASH_HELPER_H

#include "stm32h7xx_hal.h"
#include <stdbool.h>
#include <stdint.h>

/**
  * @brief  Initializes the flash helper module
  * @retval HAL status
  * @note Must be called before any other flash operations
  */
HAL_StatusTypeDef FLASH_HELPER_Init(void);

#if (defined(FLASH_TYPE_PAGE) && !defined(FLASH_TYPE_SECTOR)) || defined(DOXYGEN)
/**
  * @brief  Erases a flash page
  * @note This function is only available if FLASH_TYPE_PAGE is defined in your project settings
  * @param  page: Page number to erase
  * @retval HAL status
  * @note Page size is defined by FLASH_PAGE_SIZE
  */
HAL_StatusTypeDef FLASH_HELPER_ErasePage(uint32_t page);
#endif

#if (defined(FLASH_TYPE_SECTOR) && !defined(FLASH_TYPE_PAGE)) || defined(DOXYGEN)
/**
  * @brief  Erases a flash sector
  * @note This function is only available if FLASH_TYPE_SECTOR is defined in your project settings
  * @param  sector: Sector number to erase
  * @retval HAL status
  */
HAL_StatusTypeDef FLASH_HELPER_EraseSector(uint32_t sector);
#endif

/**
  * @brief  Writes data to flash memory
  * @param  address: Starting address to write to (must be properly aligned)
  * @param  data: Pointer to data to write
  * @param  size: Size of data in bytes
  * @retval HAL status
  * @note For STM32H7, address and size must be 32-byte aligned
  * @note Flash must be erased before writing
  */
HAL_StatusTypeDef FLASH_HELPER_Write(uint32_t address, uint8_t *data, uint32_t size);

/**
  * @brief  Reads data from flash memory
  * @param  address: Starting address to read from
  * @param  data: Pointer to buffer to store read data
  * @param  size: Size of data to read in bytes
  * @retval HAL status
  */
HAL_StatusTypeDef FLASH_HELPER_Read(uint32_t address, uint8_t *data, uint32_t size);

/**
  * @brief  Verifies if flash memory is empty (all bytes = 0xFF)
  * @param  address: Starting address to verify
  * @param  size: Size of memory to verify in bytes
  * @retval true if empty, false otherwise
  */
bool FLASH_HELPER_IsEmpty(uint32_t address, uint32_t size);

#endif /* FLASH_HELPER_H */
