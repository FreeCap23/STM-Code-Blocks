/*
 @licstart  The following is the entire license notice for the JavaScript code in this file.

 The MIT License (MIT)

 Copyright (C) 1997-2020 by Dimitri van Heesch

 Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 and associated documentation files (the "Software"), to deal in the Software without restriction,
 including without limitation the rights to use, copy, modify, merge, publish, distribute,
 sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all copies or
 substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 @licend  The above is the entire license notice for the JavaScript code in this file
*/
var NAVTREE =
[
  [ "STM Code Blocks", "index.html", [
    [ "01. The STM32 Code Structure", "md_Guides_201_8STM32__Code__Structure.html", [
      [ "A. General info", "md_Guides_201_8STM32__Code__Structure.html#autotoc_md2", null ],
      [ "B. The STM32 equivalent of setup() and loop() functions found in Arduine IDE", "md_Guides_201_8STM32__Code__Structure.html#autotoc_md3", null ],
      [ "C. Global Variables - Declaration, definition and inclusion in the main source code", "md_Guides_201_8STM32__Code__Structure.html#autotoc_md4", [
        [ "Global variables should be declared in a <tt>globals.h</tt> file following these steps:", "md_Guides_201_8STM32__Code__Structure.html#autotoc_md5", null ],
        [ "The global variables you declared in <tt>globals.h</tt> must be also defined (assigned default values) into a <tt>globals.c</tt> file following these steps:", "md_Guides_201_8STM32__Code__Structure.html#autotoc_md6", null ],
        [ "To make your global variables available to the main code, the <tt>globals.h</tt> file must be included into <tt>main.c</tt> file following these steps:", "md_Guides_201_8STM32__Code__Structure.html#autotoc_md7", null ]
      ] ],
      [ "D. Creating a software module and its local variables", "md_Guides_201_8STM32__Code__Structure.html#autotoc_md8", [
        [ "Create the header file of the software module:", "md_Guides_201_8STM32__Code__Structure.html#autotoc_md9", null ],
        [ "Create the source file of the software module:", "md_Guides_201_8STM32__Code__Structure.html#autotoc_md10", null ]
      ] ]
    ] ],
    [ "02. Device Configuration Setup Guide", "md_Guides_202_8Device__Configuration.html", [
      [ "A. Set up a GPIO as a Digital Input or as Digital Output", "md_Guides_202_8Device__Configuration.html#autotoc_md12", null ],
      [ "B. Set up a GPIO as an analog Input", "md_Guides_202_8Device__Configuration.html#autotoc_md13", null ],
      [ "C. Set up a GPIO as an PWM Output", "md_Guides_202_8Device__Configuration.html#autotoc_md14", null ],
      [ "D. Set up a GPIO as an Interrupt Capable Digital Input", "md_Guides_202_8Device__Configuration.html#autotoc_md15", null ],
      [ "E. Set up GPIOs for UART Communication", "md_Guides_202_8Device__Configuration.html#autotoc_md16", null ],
      [ "F. Set up GPIOs for SPI Communication", "md_Guides_202_8Device__Configuration.html#autotoc_md17", null ],
      [ "G. Set up GPIOs for I2C Communication", "md_Guides_202_8Device__Configuration.html#autotoc_md18", null ]
    ] ],
    [ "03. Timer Clock Guide", "md_Guides_203_8Timer__Setup.html", [
      [ "APBx Peripheral Clocks", "md_Guides_203_8Timer__Setup.html#autotoc_md20", null ]
    ] ],
    [ "04. Using the ADC in DMA mode effectively", "md_Guides_204_8ADC__with__DMA__Setup.html", [
      [ "Setup", "md_Guides_204_8ADC__with__DMA__Setup.html#autotoc_md22", null ],
      [ "Example usage", "md_Guides_204_8ADC__with__DMA__Setup.html#autotoc_md23", null ]
    ] ],
    [ "05. STM32CubeIDE Debugging Guide", "md_Guides_205_8Debugger__Guide.html", [
      [ "Build and Flash the Project", "md_Guides_205_8Debugger__Guide.html#autotoc_md26", null ],
      [ "Set Breakpoints", "md_Guides_205_8Debugger__Guide.html#autotoc_md27", null ],
      [ "Step Through Code", "md_Guides_205_8Debugger__Guide.html#autotoc_md28", null ],
      [ "Inspect Variables", "md_Guides_205_8Debugger__Guide.html#autotoc_md30", null ],
      [ "Memory and Registers", "md_Guides_205_8Debugger__Guide.html#autotoc_md32", null ],
      [ "Exit Debug Mode", "md_Guides_205_8Debugger__Guide.html#autotoc_md34", null ]
    ] ],
    [ "06. LCD with I2C Module.md", "md_Guides_206_8LCD__with__I2C__Module.html", [
      [ "Installation", "md_Guides_206_8LCD__with__I2C__Module.html#autotoc_md36", null ],
      [ "How to Configure It", "md_Guides_206_8LCD__with__I2C__Module.html#autotoc_md37", [
        [ "1. Configure I²C Peripheral", "md_Guides_206_8LCD__with__I2C__Module.html#autotoc_md38", null ],
        [ "2. Define and Initialize the LCD Handle", "md_Guides_206_8LCD__with__I2C__Module.html#autotoc_md39", null ]
      ] ],
      [ "Displaying a formatted string", "md_Guides_206_8LCD__with__I2C__Module.html#autotoc_md41", null ],
      [ "Example usage", "md_Guides_206_8LCD__with__I2C__Module.html#autotoc_md42", null ],
      [ "How do I find the address??", "md_Guides_206_8LCD__with__I2C__Module.html#autotoc_md43", null ]
    ] ],
    [ "07. FLASH Helper Functions", "md_Guides_207_8FLASH__Helper.html", null ],
    [ "08. Using a Rotary Encoder", "md_Guides_208_8Using__a__Rotary__Encoder.html", [
      [ "Pin configuration", "md_Guides_208_8Using__a__Rotary__Encoder.html#autotoc_md46", null ],
      [ "Setting up the Interrupt Request Handlers", "md_Guides_208_8Using__a__Rotary__Encoder.html#autotoc_md47", null ]
    ] ],
    [ "09. Parsing Commands", "md_Guides_209_8Parsing__commands.html", [
      [ "How to Install It", "md_Guides_209_8Parsing__commands.html#autotoc_md50", null ],
      [ "How to Configure It", "md_Guides_209_8Parsing__commands.html#autotoc_md52", null ],
      [ "How to Use It", "md_Guides_209_8Parsing__commands.html#autotoc_md54", null ],
      [ "Use Examples", "md_Guides_209_8Parsing__commands.html#autotoc_md56", [
        [ "Example 1 – Full Command", "md_Guides_209_8Parsing__commands.html#autotoc_md57", null ],
        [ "Example 2 – Name and Int Only", "md_Guides_209_8Parsing__commands.html#autotoc_md58", null ],
        [ "Example 3 – Name Only", "md_Guides_209_8Parsing__commands.html#autotoc_md59", null ],
        [ "Example 4 – Invalid Format", "md_Guides_209_8Parsing__commands.html#autotoc_md60", null ]
      ] ]
    ] ],
    [ "List of helper functions and modules", "md_Guides_2List__of__helper__functions__and__modules.html", null ],
    [ "Topics", "topics.html", "topics" ],
    [ "Data Structures", "annotated.html", [
      [ "Data Structures", "annotated.html", "annotated_dup" ],
      [ "Data Structure Index", "classes.html", null ],
      [ "Data Fields", "functions.html", [
        [ "All", "functions.html", null ],
        [ "Variables", "functions_vars.html", null ]
      ] ]
    ] ],
    [ "Files", "files.html", [
      [ "File List", "files.html", "files_dup" ],
      [ "Globals", "globals.html", [
        [ "All", "globals.html", null ],
        [ "Functions", "globals_func.html", null ],
        [ "Macros", "globals_defs.html", null ]
      ] ]
    ] ]
  ] ]
];

var NAVTREEINDEX =
[
"adxl345__registers_8h_source.html"
];

var SYNCONMSG = 'click to disable panel synchronisation';
var SYNCOFFMSG = 'click to enable panel synchronisation';