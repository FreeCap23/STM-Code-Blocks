@page Peripheral_Setup_Guide Peripheral Setup Guide

This guide explains how to configure basic I/O and peripheral functionality on STM32 microcontrollers using STM32CubeIDE.

## Digital Input / Output

1. Open your `.ioc` file in STM32CubeIDE.
2. In the **Pinout & Configuration** tab, click on a GPIO pin.
3. Set it as:
   - **GPIO_Output** for output (e.g., driving an LED)
   - **GPIO_Input** for input (e.g., reading a button)
4. Go to **Configuration > GPIO** to verify settings like pull-up/pull-down.
5. In code, use HAL functions:
```c
// Output
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);

// Input
GPIO_PinState state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);

// If you set a label on the pin earlier, for example BLUE_LED, you can write this:
HAL_GPIO_WritePin(BLUE_LED_GPIO_Port, BLUE_LED_Pin, GPIO_PIN_SET);
// These definitions are stored in main.h
```

## Analog Input

1. Enable **ADC peripheral** under **Analog**.
2. Pick the **Channel** you want. Note that you cannot reassign the pins of the Channels.
3. Configure ADC settings (resolution, alignment, etc.)
4. Generate code.
5. In your code:

a. For a single channel:
```c
uint32_t adc_val = 0;
HAL_ADC_Start(&hadc1);
HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
adc_val = HAL_ADC_GetValue(&hadc1);
HAL_ADC_Stop(&hadc1);
```
b. For multiple channels:

First, make sure **Number of Conversion** in **Configuration > Parameter Settings > ADC_Regular_ConversionMode** matches the number of channels you want to convert. Then, for each **Rank**, assign a Channel.

For example, if Rank 1 is Channel 1 and Rank 2 is Channel 2:
```c
uint32_t adc_val_channel1 = 0;
uint32_t adc_val_channel2 = 0;
HAL_ADC_Start(&hadc1);
// Once polling starts, you don't need to call PollForConversion if you set the ADC to run in Continuous mode. If it is in Single mode, then you need to PollForConversion every time you need new values.
HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
adc_val_channel1 = HAL_ADC_GetValue(&hadc1);
adc_val_channel2 = HAL_ADC_GetValue(&hadc1);
HAL_ADC_Stop(&hadc1);
```

## PWM Output
To generate **PWM signals**, we need to use **Timers**. Pick a timer and configure it:
- Clock Source: Choose your clock source. If you don't know what to pick, choose Internal Clock.
- Channel`x`: **PWM Generation `CHx`**. `CHxN` means the same output as `CHx` but inversed. You can both `CHx` and `CHxN` to generate synchronised, opposite PWM signals by simply choosing **PWM Generation CHx CHxN**.
- Under **Configuration > Parameter Settings** use [this site](https://deepbluembedded.com/stm32-pwm-calculator/) to get the values you need. **Make sure to enable auto-reload preload!**
    - For **clock frequency**, you need to see which `APBx` your timer uses. This can be found in your MCU's data sheet, in the **Block Diagram**.

To change the PWM's duty cycle programatically:
```c
TIMx->CCRy = duty_cycle;
```
Where `x` is your Timer's number and `y` is the number of the Channel whose Duty Cycle you want to update.

## Triggering an interrupt on an arbitrary pin
- Pick the pin you want to generate interrupts on. Note that not all pins have the ability to generate external interrupts.
- Configure the pin as `GPIO_EXTIx`
- Under **GPIO > Configuration > Pxx** you can configure your interrupt to generate on falling, rising, or both edges. Choose **No pull-up and no pull-down**.
- Under **NVIC > Configuration** make sure **EXTI line interrupts** is enabled.
- Generate the code.

In your `main.c` you need to add the **ISR** (**I**nterrupt **S**ervice **R**outine):
```c
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == GPIO_PIN_9) // If The INT Source Is EXTI Line9 we set up earlier
    {
        // Do whatever you need to do
    }
}
```

## UART Communication
To talk with a computer, we can use one of the USART modules on our MCU. For this example we'll use a USART module that can create a Virtual Com Port on our USB Connector. On the NUCLEO-H7A3ZI, this is USART3.

> ℹ️ Some boards (Like the F411E Discovery) do not support VCP (**V**irtual **C**OM **P**ort), meaning you cannot use the ST-Link USB port as a serial communication port. If that is the case, you need to use the RX/TX pins themselves and use a USB to Serial converter to talk to the PC.

Under **Connectivity > USART3**
- Mode: Asynchronous

Now, under **Configuration > Parameter Settings**
- Baud Rate: Set it to whatever you want.

> **⚠️ Setting this too high may result in lost bytes when receiving data in bulk without DMA**
- Word Length: Leave this to 8 bits (including parity)
- Parity: I've had some issues with parity so I recommend you just leave this to Disabled unless absolutely necessary.

Under **Configuration > NVIC Settings**, enable USART3 global interrupt.

Now we're ready for the code:
### Transmitting
```c
// Transmitting a simple message
uint8_t *message = "Hello world.\r\n"; // \r\n is for new line and carriage return.
HAL_UART_Transmit(&huart3, message, strlen(message) * sizeof(uint8_t), 10);
```
Let's go over the arguments to this function.
- `&huart3`: Reference to the handle of the uart module to transmit the message on
- `message`: the message...
- `strlen(message) * sizeof(uint8_t)`: The size of the message, in bytes.
- `10`: Timeout. How much time (in ms) can pass until it stops trying to send the message.

### Receiving
```c
// Receiving a message
#define BUFFER_SIZE 64
uint8_t buffer[BUFFER_SIZE]; // We need to allocate memory to store the message in
HAL_UART_Receive(&huart3, buffer, BUFFER_SIZE, 10);
```
Let's go over the arguments to this function.
- `&huart3`: Reference to the handle of the uart module
- `buffer`: The buffer where the message will be stored
- `BUFFER_SIZE`: How many bytes to receive
- `10`: Timeout. How much time (in ms) can pass until it stops trying to receive a message.