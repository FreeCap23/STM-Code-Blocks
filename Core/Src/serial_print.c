/**
 * @file serial_print.c
 * @brief TODO: Write a brief description of this file
 *
 * If you're looking for the GUIDE on using this file, it's called
 * 10. Send Serial Data Module
 *
 * TODO: Write a detailed description of this file
 *
 * @date Created on: Jul 16, 2025
 * @author Dionisie Stratulat
 */

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include "stm32h7xx_hal.h"

uint8_t SerialPrint(UART_HandleTypeDef *huart, const char *format, ...) {
	if (huart == NULL)
		return 1;

	const uint8_t USB_PRINT_BUFFER_SIZE = 64;
	char buffer[USB_PRINT_BUFFER_SIZE];

	// Start collecting extra arguments for the message.
	va_list args;
	va_start(args, format);

	// Put the message and the extra arguments into the buffer.
	// For example: if format is "Hi %s", and name is "Tom", the buffer will be "Hi Tom".
	if (vsnprintf(buffer, USB_PRINT_BUFFER_SIZE, format, args) < 0)
		return 1; // vsnprintf returns a negative number on error

	// We are done looking at the extra arguments.
	va_end(args);

	// Now we send the message over the USB wire using UART.
	// We tell it where the message is (buffer), how long it is, and how long to wait (10 ticks).
	return HAL_UART_Transmit(huart, (uint8_t *)buffer, strlen(buffer), 10);
}

uint8_t SerialPrintLn(UART_HandleTypeDef *huart, const char *format, ...) {
	if (huart == NULL)
			return 1;

	const uint8_t USB_PRINT_BUFFER_SIZE = 64;
	char buffer[USB_PRINT_BUFFER_SIZE];

    // Start collecting extra arguments for the message.
    va_list args;
    va_start(args, format);

    // Put the message and the extra arguments into the buffer.
	// For example: if format is "Hi %s", and name is "Tom", the buffer will be "Hi Tom".
    if (vsnprintf(buffer, USB_PRINT_BUFFER_SIZE, format, args) < 0)
		return 1; // vsnprintf returns a negative number on error

    // We are done looking at the extra arguments.
    va_end(args);

	// Now we send the message over the USB wire using UART.
	// We tell it where the message is (buffer), how long it is, and how long to wait (10 ticks).
    if (HAL_UART_Transmit(huart, (uint8_t *)buffer, strlen(buffer), 10) != HAL_OK)
    	return 1;

    // Send a special "new line" message — this moves the cursor to the next line.
    if (HAL_UART_Transmit(huart, (uint8_t *)"\r\n", 2, 10) != HAL_OK)
    	return 1;

    return HAL_OK;
}
