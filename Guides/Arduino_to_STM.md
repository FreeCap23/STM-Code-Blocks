# STM32 HAL Project Structure for Arduino Users

If you're used to programming in Arduino (where everything is typically in one .ino file with `setup()` and `loop()`), STM32 projects generated with STM32CubeMX are more structured and split across multiple files. Here's how to map the concepts:

## Where to Add Global and Local Variables
### Global Variables

In STM32CubeMX-generated code, global variables should be declared in a new file `globals.h`.

Example
```c
/* === globals.h === */
extern int myGlobalVar;  // Declaration

/* === globals.c === */
int myGlobalVar = 0;     // Definition

/* === anywhere else === */
#include "globals.h"
if (myGlobalVar < 2) {   // Using the variable
  // Do something
}
```
> ⚠️ Only define a global variable once, in the `globals.c` file. If you define it multiple times, you will get a compilation error.

## Libraries Required Based on Variable Types

STM32 uses standard C types and headers. You often need to include standard headers manually for specific types.
| Variable Type              | Header File Required    | Notes                        |
| -------------------------- | ----------------------- | ---------------------------- |
| `int`, `char`, `float`     | No extra headers needed | Built-in types in C          |
| `bool`                     | `#include <stdbool.h>`  | `true` and `false` constants |
| `uint8_t`, `int16_t`, etc. | `#include <stdint.h>`   | Fixed-width integer types    |


Examples:

```c
#include <stdint.h>   // for uint8_t, int32_t, etc.
#include <stdbool.h>  // for bool, true, false

uint8_t myByte = 0;
bool isReady = false;
```

## What Is the Equivalent of setup() and loop()?
| Arduino   | STM32 (CubeMX/HAL)                                                         | Notes                         |
| --------- | -------------------------------------------------------------------------- | ----------------------------- |
| `setup()` | Code inside `int main(void)` after `HAL_Init()` and `SystemClock_Config()` | Initialization code goes here |
| `loop()`  | Manual infinite loop: `while (1)`                                          | Put your repetitive code here |


Example in `main.c`:
```c
int main(void)
{
  /* USER CODE BEGIN 1 */    // ← Initialization code before HAL and peripherals get initialised
  /* USER CODE END 1 */

  HAL_Init();                // HAL initialization
  SystemClock_Config();      // Clock setup

  MX_GPIO_Init();            // Peripherals
  MX_USART3_UART_Init();

  /* USER CODE BEGIN 2 */     // ← Initialization code here (like Arduino's setup())
  /* USER CODE END 2 */

  while (1)
  {
    /* USER CODE BEGIN 3 */   // ← Repeating code here (like Arduino's loop())
    /* USER CODE END 3 */
  }
}
```
> ℹ️ **Important**: Only write your own code in sections marked with comments like `/* USER CODE BEGIN x */` and `/* USER CODE END x */`.
These regions are preserved when you regenerate code with STM32CubeMX.
Anything outside these blocks may be deleted or overwritten.