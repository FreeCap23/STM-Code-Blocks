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
    [ "06. LCD Drivers.md", "md_Guides_206_8LCD.html", [
      [ "I2C", "md_Guides_206_8LCD.html#autotoc_md36", [
        [ "A. What you can do with it", "md_Guides_206_8LCD.html#autotoc_md37", null ],
        [ "B. How to Install It", "md_Guides_206_8LCD.html#autotoc_md38", null ],
        [ "C. How to Configure It", "md_Guides_206_8LCD.html#autotoc_md39", [
          [ "1. Configure I²C Peripheral", "md_Guides_206_8LCD.html#autotoc_md40", null ],
          [ "2. Define and Initialize the LCD Handle", "md_Guides_206_8LCD.html#autotoc_md41", null ]
        ] ],
        [ "How do I find the address??", "md_Guides_206_8LCD.html#autotoc_md42", null ],
        [ "D. How to Use It", "md_Guides_206_8LCD.html#autotoc_md44", [
          [ "Clear the display", "md_Guides_206_8LCD.html#autotoc_md46", null ],
          [ "Set the display cursor position", "md_Guides_206_8LCD.html#autotoc_md48", null ],
          [ "Display text", "md_Guides_206_8LCD.html#autotoc_md50", null ],
          [ "Display an int or float", "md_Guides_206_8LCD.html#autotoc_md52", null ]
        ] ]
      ] ],
      [ "Parallel", "md_Guides_206_8LCD.html#autotoc_md54", [
        [ "A. What you can do with it", "md_Guides_206_8LCD.html#autotoc_md55", null ],
        [ "B. How to install it", "md_Guides_206_8LCD.html#autotoc_md56", null ],
        [ "C. How to configure it", "md_Guides_206_8LCD.html#autotoc_md57", [
          [ "Peripheral configuration", "md_Guides_206_8LCD.html#autotoc_md58", null ],
          [ "Code configuration", "md_Guides_206_8LCD.html#autotoc_md59", null ]
        ] ],
        [ "D. How to use it", "md_Guides_206_8LCD.html#autotoc_md60", [
          [ "Include the driver", "md_Guides_206_8LCD.html#autotoc_md61", null ],
          [ "Initialise the display and print something", "md_Guides_206_8LCD.html#autotoc_md62", null ],
          [ "Printing an int or float", "md_Guides_206_8LCD.html#autotoc_md63", null ]
        ] ]
      ] ]
    ] ],
    [ "07. FLASH Helper Functions", "md_Guides_207_8FLASH__Helper.html", null ],
    [ "08. Using a Rotary Encoder", "md_Guides_208_8Using__a__Rotary__Encoder.html", [
      [ "Pin configuration", "md_Guides_208_8Using__a__Rotary__Encoder.html#autotoc_md66", null ],
      [ "Setting up the Interrupt Request Handlers", "md_Guides_208_8Using__a__Rotary__Encoder.html#autotoc_md67", null ]
    ] ],
    [ "09. Parsing Commands", "md_Guides_209_8Parsing__commands.html", [
      [ "How to Install It", "md_Guides_209_8Parsing__commands.html#autotoc_md70", null ],
      [ "How to Configure It", "md_Guides_209_8Parsing__commands.html#autotoc_md72", null ],
      [ "How to Use It", "md_Guides_209_8Parsing__commands.html#autotoc_md74", null ],
      [ "Use Examples", "md_Guides_209_8Parsing__commands.html#autotoc_md76", [
        [ "Example 1 – Full Command", "md_Guides_209_8Parsing__commands.html#autotoc_md77", null ],
        [ "Example 2 – Name and Int Only", "md_Guides_209_8Parsing__commands.html#autotoc_md78", null ],
        [ "Example 3 – Name Only", "md_Guides_209_8Parsing__commands.html#autotoc_md79", null ],
        [ "Example 4 – Invalid Format", "md_Guides_209_8Parsing__commands.html#autotoc_md80", null ]
      ] ]
    ] ],
    [ "10.Send Serial Data Module", "md_Guides_210_8Send__Serial__Data__Module.html", [
      [ "What You Can Do With It", "md_Guides_210_8Send__Serial__Data__Module.html#autotoc_md82", null ],
      [ "How to Install It", "md_Guides_210_8Send__Serial__Data__Module.html#autotoc_md84", null ],
      [ "***Copy from where.\"", "md_Guides_210_8Send__Serial__Data__Module.html#autotoc_md85", null ],
      [ "How to Configure It", "md_Guides_210_8Send__Serial__Data__Module.html#autotoc_md86", null ],
      [ "How to Use It", "md_Guides_210_8Send__Serial__Data__Module.html#autotoc_md88", [
        [ "a. Basic Usage:", "md_Guides_210_8Send__Serial__Data__Module.html#autotoc_md89", null ],
        [ "b. Output:", "md_Guides_210_8Send__Serial__Data__Module.html#autotoc_md90", null ],
        [ "c. Notes:", "md_Guides_210_8Send__Serial__Data__Module.html#autotoc_md91", null ]
      ] ]
    ] ],
    [ "11.Using the ADXL345 Accelerometer", "md_Guides_211_8Using__the__ADXL345__driver.html", [
      [ "Installation", "md_Guides_211_8Using__the__ADXL345__driver.html#autotoc_md93", null ],
      [ "Configuration", "md_Guides_211_8Using__the__ADXL345__driver.html#autotoc_md95", null ],
      [ "Usage", "md_Guides_211_8Using__the__ADXL345__driver.html#autotoc_md104", null ]
    ] ],
    [ "12.us Resolution Timer (get_tick_us & delay_us)", "md_Guides_212_8us__resolution__timer.html", [
      [ "Description", "md_Guides_212_8us__resolution__timer.html#autotoc_md106", null ],
      [ "Installation", "md_Guides_212_8us__resolution__timer.html#autotoc_md108", null ],
      [ "Configuration – STM32CubeMX", "md_Guides_212_8us__resolution__timer.html#autotoc_md110", null ],
      [ "Usage", "md_Guides_212_8us__resolution__timer.html#autotoc_md112", null ],
      [ "Usage Test (VALIDATED ON STM32H7A3 NUCLEO)", "md_Guides_212_8us__resolution__timer.html#autotoc_md114", null ]
    ] ],
    [ "13.Receive serial commands", "md_Guides_213_8Receive__Serial__commands.html", [
      [ "Description", "md_Guides_213_8Receive__Serial__commands.html#autotoc_md116", null ],
      [ "Installation", "md_Guides_213_8Receive__Serial__commands.html#autotoc_md117", null ],
      [ "Configuring", "md_Guides_213_8Receive__Serial__commands.html#autotoc_md118", [
        [ "In CubeMX:", "md_Guides_213_8Receive__Serial__commands.html#autotoc_md119", null ],
        [ "In code:", "md_Guides_213_8Receive__Serial__commands.html#autotoc_md120", null ]
      ] ],
      [ "Usage", "md_Guides_213_8Receive__Serial__commands.html#autotoc_md121", null ]
    ] ],
    [ "14.Writing a task scheduler", "md_Guides_214_8Writing__a__task__scheduler.html", [
      [ "Description", "md_Guides_214_8Writing__a__task__scheduler.html#autotoc_md123", null ],
      [ "Installation", "md_Guides_214_8Writing__a__task__scheduler.html#autotoc_md125", null ],
      [ "Configuration", "md_Guides_214_8Writing__a__task__scheduler.html#autotoc_md127", null ],
      [ "Usage", "md_Guides_214_8Writing__a__task__scheduler.html#autotoc_md130", null ]
    ] ],
    [ "99.Wishlist", "md_Guides_299_8Wishlist.html", null ],
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
"adxl345_8c.html"
];

var SYNCONMSG = 'click to disable panel synchronisation';
var SYNCOFFMSG = 'click to enable panel synchronisation';