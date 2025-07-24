/**
 * @file flash_helper_h7a3.h
 * @brief Flash memory utility functions for STM32H7A3 MCUs using the HAL library.
 *
 * This module provides helper functions for reading, writing, and erasing internal Flash memory
 * on STM32H7A3 series microcontrollers.
 *
 * It uses 64-bit double-word aligned programming as required by the STM32H7 flash memory interface.
 *
 * Example usage:
 * @code
 * #include "flash_helper_h7.h"
 * #include <string.h>
 *
 * const char message[] = "Hello from FLASH memory";
 * uint8_t read_buffer[sizeof(message)];
 * uint32_t flash_address = 0x08020000; // Must be 16-byte aligned and in valid flash region
 *
 * // Erase the sector before writing
 * if (Flash_Erase(flash_address) == HAL_OK) {
 *     // Prepare a 16-byte aligned buffer (padded if needed)
 *     uint8_t write_buffer[((sizeof(message) + 15) / 16) * 16] = {0xFF};
 *     memcpy(write_buffer, message, sizeof(message));
 *
 *     // Write to Flash (length in bytes)
 *     if (Flash_Write(flash_address, (uint64_t*)write_buffer, sizeof(write_buffer)) == HAL_OK) {
 *         // Read back the data
 *         Flash_Read(flash_address, read_buffer, sizeof(read_buffer));
 *     }
 * }
 * @endcode
 * @date Created on: Jul 21, 2025
 * @author Dionisie Stratulat
 */

#ifndef FLASH_HELPER_H7_H
#define FLASH_HELPER_H7_H

#include "stm32h7xx_hal.h"
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup helper_functions
 * @{
 * @defgroup flash_memory FLASH Memory
 * @brief Functions for writing, reading and erasing non-volatile memory
 * @see flash_helper_h7a3.h for example usage.
 * @{
 */
/**
 * @brief Writes a buffer of 64-bit values to Flash memory.
 *
 * @note The address must be 8-byte aligned, and Flash must be previously erased.
 *
 * @param address  Destination Flash memory address (must be 8-byte aligned)
 * @param data     Pointer to the 64-bit data buffer
 * @param length   Number of 64-bit values to write
 * @return HAL_OK on success, otherwise HAL_ERROR or HAL_BUSY
 */
HAL_StatusTypeDef Flash_Write(uint32_t address, uint64_t* data, size_t length);

/**
 * @brief Reads data from Flash memory into a byte buffer.
 *
 * @param address  Source Flash memory address
 * @param data     Pointer to destination buffer
 * @param length   Number of bytes to read
 */
void Flash_Read(uint32_t address, uint8_t* data, size_t length);

/**
 * @brief Erases the Flash sector that contains the specified address.
 *
 * @note This erases the entire 128 KB sector.
 *
 * @param address  Address within the sector to erase
 * @return HAL_OK on success, otherwise HAL_ERROR or HAL_BUSY
 */
HAL_StatusTypeDef Flash_Erase(uint32_t address);

/**
 * @}
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif // FLASH_HELPER_H7_H
