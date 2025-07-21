# LCD With I2C

[This library](https://github.com/alixahedi/I2C-LCD-STM32) allows us to easily use an LCD through I<sup>2</sup>C. It supports displays with sizes **16x2, 16x4, 20x2, 20x4**.

## Installation
For installation instructions, [see the README.md](https://github.com/alixahedi/I2C-LCD-STM32?tab=readme-ov-file#installation).

## Displaying a formatted string
In order to display a formatted string, we first need to build the string in a buffer:
```c
char buffer[64];
sprintf(buffer, "Pi: %.3f", 3.1415926535);
lcd_puts(&hlcd, buffer);
```

This will display `Pi: 3.142`. Note how the number was automatically rounded. For more format specifiers, see [the Parameters section of the printf documentation](https://cplusplus.com/reference/cstdio/printf/).

## How do I find the address??
First, try addresses `0x20` and `0x4E`. If those don't work, try running this snippet of code:

```c
/* ----- >8 snip ----- */
/* USER CODE BEGIN PV */
I2C_LCD_HandleTypeDef hlcd;
/* USER CODE END PV */
/* ----- >8 snip ----- */

/* ----- >8 snip ----- */
/* USER CODE BEGIN 2 */
hlcd.hi2c = &hi2c1; // Change this to your i2c handle
char buffer[64];
for (int8_t address = 0; address < 128; address++) {
  // Convert the address to a string in hex format
  sprintf(buffer, "Address: %#X", address);
  hlcd.address = address;
  lcd_init(&hlcd);
  lcd_clear(&hlcd);
  lcd_puts(&hlcd, buffer);
}
/* ----- >8 snip ----- */
```
You should see the address printed on your display.