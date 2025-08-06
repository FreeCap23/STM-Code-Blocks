/**
 * @file command_parser.h
 * @brief TODO: Write a brief description of this file
 *
 * TODO: Write a detailed description of this file
 *
 * @date Created on: Jul 16, 2025
 * @author Dionisie Stratulat
 */
#ifndef INC_COMMAND_PARSER_H_
#define INC_COMMAND_PARSER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

#define COMMAND_BUFFER_SIZE 8 // Make this larger if needed

// Declared here, defined in command_parser.c
extern bool command_ready_to_be_processed;
extern uint8_t command_buff[COMMAND_BUFFER_SIZE];

/**
 * @defgroup helper_functions Helper Functions
 * @brief Easy to use helper functions for working with various interfaces and devices
 * @{
 *
 * @addtogroup command_parser Command Parser
 * @brief Parses commands and stores the name and arguments of the commands in the given pointers' locations
 * @{
 */

/**
 * @brief Parses a command and stores the command ID and argument in the given pointers' locations.
 *
 * This function works with the following format:
 * <COMMAND_ID:COMMAND_ARGUMENT>
 * Both COMMAND_ID and COMMAND_ARGUMENT are integers.
 *
 * Example usage:
 * @code
 *     int command_id;
 *     int command_arg;
 *     int status = ParseCommand("<10:42>", &command_id, &command_arg);
 *     // status == 2 (both values parsed)
 * @endcode
 *
 * In the case that the argument is missing, the corresponding output pointer will remain unset (0).
 *
 * @param command       Pointer to the command buffer
 * @param command_id    Pointer to where the parsed command ID should be stored (optional)
 * @param command_arg   Pointer to where the parsed command argument should be stored (optional)
 * @returns int Status code:
 *          - 0 = Parsing failed
 *          - 1 = Only command ID parsed
 *          - 2 = Both command ID and argument parsed
 */
int ParseCommand(const char *command, int *command_id, int *command_arg);
/**
 * @}
 * @}
 */

#endif /* INC_COMMAND_PARSER_H_ */
