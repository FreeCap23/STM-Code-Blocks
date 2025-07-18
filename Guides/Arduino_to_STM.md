# STM32 HAL Project Structure for Arduino Users

If you're used to programming in Arduino (where everything is typically in one .ino file with `setup()` and `loop()`), STM32 projects generated with STM32CubeMX are more structured and split across multiple files. Here's how to map the concepts:

## A. Global Variables - Declaration and definition

### Global variables should be declared in a `globals.h` file following these steps:
- navigate to "Project Explorer / YourProject / Core / Inc";
- right-click on "Inc" folder;
- choose "New / Header file";
- in the "New Header File" dialog window write "globals.h" in the "Header file:" field and choose "Default C header template" in "Template" field. Click "Finish".
- `globals.h` file opens automatically with some predefined code in it. Place your global variables just before the `endif /* GLOBALS_H_ */` line.
- include also the stdbool.h and stdint.h libraries (to make the code able to use boolean and int type variables).

Example of how the content of `globals.h` content should look like:
```c
/* === globals.h === */
#ifndef GLOBALS_H_
#define GLOBALS_H_
#include <stdbool.h>
#include <stdint.h>

extern int globalVariableName1;  // Declaration of a 1st variable
extern int globalVariableName2;  // Declaration of a 2nd variable
extern int globalVariableName3;  // Declaration of a 3rd variable

#endif /* GLOBALS_H_ */
```
### The global variables you declared in `globals.h` must be also defined (assigned default values) into a `globals.c` file following these steps:
- navigate to "Project Explorer / YourProject / Core / Src";
- right-click on "Src" folder;
- choose "New / Source file";
- in the "New Source File" dialog window write "globals.c" in the "Source file:" field and choose "Default C header template" in "Template" field. Click "Finish".
- `globals.c` file opens automatically. Add the '#include "global_variables.h"' line and set the type and the default value of each of your global variables.

Example of how the content of `globals.c` content should look like:
```c
/* === globals.c === */
#include "global_variables.h"
int globalVariableName1 = 0;  // Definition of the 1st variable
int globalVariableName2 = 0;  // Definition of the 2nd variable
int globalVariableName3 = 0;  // Definition of the 3rd variable
```


C. To make you global variables available to the main code, the `globals.h` file must be included into `main.c` file following these steps:
- navigate to "Project Explorer / YourProject / Core / Src" and open the `main.c` file;
- search for the `'Private includes'` section and include your `globals.h` file as shown in the example below.
```c
/* === main.c === */

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "globals.h"
/* USER CODE END Includes */
```
```c
/* === anywhere else.c === */
#include "globals.h"
int localVariableName = globalVariableName;
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
