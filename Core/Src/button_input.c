#include "button_input.h"

// ---- Internal Structures ----
typedef struct {
    bool (*read)(void);       // GPIO read function
    bool stable_state;        // debounced state
    bool last_state;          // last physical read
    uint32_t last_change;     // last debounce time
    uint32_t hold_counter;    // how long the button has been held (ms)
} Button;

static Button buttons[MAX_BUTTONS];

// ---- Event Queue ----
typedef struct {
    ButtonEvent buffer[EVENT_BUFFER_SIZE];
    volatile uint8_t head;
    volatile uint8_t tail;
} EventQueue;

static EventQueue event_queue = { .head = 0, .tail = 0 };

// ---- Private Functions ----
static void push_event(uint8_t button_id, ButtonAction action, uint32_t timestamp) {
    uint8_t next_head = (event_queue.head + 1) % EVENT_BUFFER_SIZE;

    // Drop oldest if full
    if (next_head == event_queue.tail) {
        event_queue.tail = (event_queue.tail + 1) % EVENT_BUFFER_SIZE;
    }

    event_queue.buffer[event_queue.head].button_id = button_id;
    event_queue.buffer[event_queue.head].action    = action;
    event_queue.buffer[event_queue.head].timestamp = timestamp;

    event_queue.head = next_head;
}

// ---- Public API ----
void button_init(void) {
    for (uint8_t i = 0; i < MAX_BUTTONS; i++) {
        buttons[i].read         = 0;
        buttons[i].stable_state = false;
        buttons[i].last_state   = false;
        buttons[i].last_change  = 0;
        buttons[i].hold_counter = 0;
    }
}

void button_register(uint8_t button_id, bool (*gpio_read_fn)(void)) {
    if (button_id < MAX_BUTTONS) {
        buttons[button_id].read = gpio_read_fn;
    }
}

// Call periodically, e.g. every 1 ms from SysTick
void button_update(uint32_t now_ms) {
    for (uint8_t i = 0; i < MAX_BUTTONS; i++) {
        if (!buttons[i].read) continue; // not registered

        bool current = buttons[i].read();

        // Debounce check
        if (current != buttons[i].last_state) {
            buttons[i].last_change = now_ms;
            buttons[i].last_state  = current;
        }

        if ((now_ms - buttons[i].last_change) >= DEBOUNCE_MS) {
            if (buttons[i].stable_state != current) {
                buttons[i].stable_state = current;

                if (current) {
                    push_event(i, BUTTON_PRESS, now_ms);
                    buttons[i].hold_counter = 0; // reset on new press
                } else {
                    push_event(i, BUTTON_RELEASE, now_ms);
                }
            }
        }

        // Update hold counter if pressed
        if (buttons[i].stable_state) {
            buttons[i].hold_counter++;
        }
    }
}

// Optional: push directly from ISR if you want EXTI triggers
void button_isr_event(uint8_t button_id, uint32_t now_ms) {
    if (button_id < MAX_BUTTONS) {
        bool current = buttons[button_id].read ? buttons[button_id].read() : false;
        push_event(button_id, current ? BUTTON_PRESS : BUTTON_RELEASE, now_ms);
    }
}

int button_pop_event(ButtonEvent *ev) {
    if (event_queue.head == event_queue.tail) {
        return 0; // empty
    }

    *ev = event_queue.buffer[event_queue.tail];
    event_queue.tail = (event_queue.tail + 1) % EVENT_BUFFER_SIZE;
    return 1;
}

uint32_t button_get_hold(uint8_t button_id) {
    if (button_id < MAX_BUTTONS) {
        return buttons[button_id].hold_counter;
    }
    return 0;
}
