/**
 * @file receive_serial_commands.c
 * @brief TODO: Write a brief description of this file
 *
 * TODO: Write a detailed description of this file
 *
 * @date Created on: Aug 6, 2025
 * @author Dionisie Stratulat
 */

#include <receive_serial_commands.h>

bool command_ready_to_be_processed = false;
uint8_t command_buff[COMMAND_BUFFER_SIZE] = {0};

int ParseCommand(const char *command, int *command_id, int *command_arg) {
    // Validate required input
    if (!command) return 0;

    // Initialize outputs to default values
    if (command_id) *command_id = 0;
    if (command_arg) *command_arg = 0;

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

    // Extract the first token (command ID)
    char *token = strtok(buffer, ":");
    if (!token) return 0;

    // Trim leading spaces and parse command ID
    while (isspace((unsigned char)*token)) token++;
    if (command_id) {
        *command_id = atoi(token);
        parsed = 1;
    }

    // Try to parse the second token (command argument)
    token = strtok(NULL, ":");
    if (token && command_arg) {
        while (isspace((unsigned char)*token)) token++;
        *command_arg = atoi(token);
        parsed = 2;
    }

    return parsed;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	static uint8_t next_character_idx;
	uint8_t current_character_idx = next_character_idx++;
	if (next_character_idx >= COMMAND_BUFFER_SIZE) {
		next_character_idx = 0;
	}

	if (command_buff[current_character_idx] == '>') {
		command_ready_to_be_processed = true;
	} else {
		command_ready_to_be_processed = false;
	}

	// At this point the USART peripheral won't receive any more bytes, so we
	// need to call this function again.
	HAL_UART_Receive_IT(&huart3, &command_buff[next_character_idx], 1);
}

