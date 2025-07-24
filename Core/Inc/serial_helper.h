/**
 * @file serial_helper.h
 * @brief Helper functions for serial (UART) communication.
 *
 * This header provides declarations for utility functions to assist with
 * serial communication, typically over UART (Universal Asynchronous Receiver/Transmitter).
 * These functions may include initialization routines, data transmission,
 * and reception handlers.
 *
 * Typical use cases include:
 * - Sending debug output to a serial console
 * - Receiving commands from a host
 * - Interfacing with other microcontrollers or serial devices
 *
 * @date Created on: July 16, 2025
 * @author Dionisie Stratulat
 */

#ifndef INC_SERIAL_HELPER_H_
#define INC_SERIAL_HELPER_H_

/**
 * @addtogroup helper_functions
 * @{
 * @defgroup serial_interface Serial Interface
 * @brief Functions for writing data to a serial interface over USART
 * @{
 */
/**
 * @brief Sends a formatted message over USART (e.g., USB-to-Serial).
 *
 * This function behaves like `printf` and supports format specifiers such as `%s`, `%d`, etc.
 * The formatted string is transmitted in blocking mode using `HAL_UART_Transmit` via the given huart handle.
 *
 * @param huart	 Handle to the UART/USART module to use.
 * @param format Format string, similar to printf.
 * @param ...    Additional arguments to format into the string.
 *
 * @returns 0 on success, 1 on error.
 *
 * @note Ensure that `huart` is initialized before calling this function.
 */
uint8_t SerialPrint(UART_HandleTypeDef *huart, const char *format, ...);

/**
 * @brief Sends a formatted message over USART (e.g., USB-to-Serial), appending a new line and carriage return.
 *
 * This function behaves like `printf` and supports format specifiers such as `%s`, `%d`, etc.
 * The formatted string is transmitted in blocking mode using `HAL_UART_Transmit` via the given huart handle.
 *
 * @param huart	 Handle to the UART/USART module to use.
 * @param format Format string, similar to printf.
 * @param ...    Additional arguments to format into the string.
 *
 * @returns 0 on success, 1 on error.
 *
 * @note Ensure that `huart` is initialized before calling this function.
 */
uint8_t SerialPrintLn(UART_HandleTypeDef *huart, const char *format, ...);

/**
 * @}
 * @}
 */
#endif /* INC_SERIAL_HELPER_H_ */
