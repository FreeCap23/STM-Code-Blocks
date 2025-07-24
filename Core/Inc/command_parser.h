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

/**
 * @defgroup helper_functions Helper Functions
 * @{
 */
/**
 * @brief Parses a command and stores the name and arguments in the given pointers' locations.
 *
 * This function works with the following formats:
 * <NAME, INT, FLOAT>
 * <NAME, INT>
 * <NAME>
 *
 * Example usage:
 * @code
 *     char name[16];
 *     int my_int;
 *     float my_float;
 *     int status = ParseCommand("<MOVE, 10, 3.14>", name, &my_int, &my_float);
 *     // status == 3
 * @endcode
 *
 * In the case that some arguments are missing, such as no INT or FLOAT, the corresponding
 * output pointers will remain unset or defaulted (0 or 0.0f).
 *
 * @param command   Pointer to the command buffer
 * @param name      Pointer to where the parsed name should be stored (must be preallocated)
 * @param arg_int   Pointer to where the parsed int argument should be stored (optional)
 * @param arg_float Pointer to where the parsed float argument should be stored (optional)
 * @returns int Status code:
 *          - 0 = Parsing failed
 *          - 1 = Only name parsed
 *          - 2 = Name and int parsed
 *          - 3 = Name, int, and float parsed
 */
int ParseCommand(const char *command, char *name, int *arg_int, float *arg_float) {
    // Validate required inputs
    if (!command || !name) return 0;

    // Initialize outputs to default values
    if (arg_int) *arg_int = 0;
    if (arg_float) *arg_float = 0.0f;

    // Locate the start of the angle-bracketed section
    const char *start = strchr(command, '<');
    if (!start) return 0;
    start++;

    // Locate the closing bracket
    const char *end = strchr(start, '>');
    if (!end || end <= start) return 0;

    // Copy the contents between < and > into a temporary buffer
    char buffer[64];
    size_t len = (size_t)(end - start);
    if (len >= sizeof(buffer)) len = sizeof(buffer) - 1;
    strncpy(buffer, start, len);
    buffer[len] = '\0';

    int parsed = 0;

    // Extract the first token (name)
    char *token = strtok(buffer, ",");
    if (!token) return 0;

    // Trim leading spaces and copy the name
    while (isspace((unsigned char)*token)) token++;
    strncpy(name, token, 16);
    name[15] = '\0';  // Ensure null-termination
    parsed = 1;

    // Try to parse the second token (int argument)
    token = strtok(NULL, ",");
    if (token && arg_int) {
        while (isspace((unsigned char)*token)) token++;
        *arg_int = atoi(token);
        parsed = 2;
    }

    // Try to parse the third token (float argument)
    token = strtok(NULL, ",");
    if (token && arg_float) {
        while (isspace((unsigned char)*token)) token++;
        *arg_float = strtof(token, NULL);
        parsed = 3;
    }

    return parsed;
}
/** @} */

#endif /* INC_COMMAND_PARSER_H_ */
