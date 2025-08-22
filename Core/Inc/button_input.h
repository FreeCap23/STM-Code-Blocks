#ifndef BUTTON_INPUT_H
#define BUTTON_INPUT_H

#include <stdint.h>
#include <stdbool.h>

// ---- Configuration ----
#define MAX_BUTTONS        8     // maximum number of physical buttons
#define EVENT_BUFFER_SIZE  16    // ring buffer size
#define DEBOUNCE_MS        20    // debounce time in milliseconds

// ---- Event Types ----
typedef enum {
    BUTTON_PRESS,
    BUTTON_RELEASE
} ButtonAction;

typedef struct {
    uint8_t button_id;     // which button
    ButtonAction action;   // press or release
    uint32_t timestamp;    // system time (ms)
} ButtonEvent;

// ---- Public API ----

// Initialize driver (call once at startup)
void button_init(void);

// Register a button with a given ID and GPIO read function
// gpio_read_fn must return true if the button is physically pressed
void button_register(uint8_t button_id, bool (*gpio_read_fn)(void));

// Call this periodically from main loop or SysTick (every 1ms typical)
void button_update(uint32_t now_ms);

// Push an event from interrupt (if using EXTI lines)
// Safe to call from ISR
void button_isr_event(uint8_t button_id, uint32_t now_ms);

// Poll next event (returns 1 if event found, 0 if queue empty)
int button_pop_event(ButtonEvent *ev);

// Get hold duration counter for a button (ms held down)
uint32_t button_get_hold(uint8_t button_id);

#endif // BUTTON_INPUT_H
