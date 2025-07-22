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
    [ "The STM32 Code Structure", "md_Guides_201_8_01STM32__Code__Structure.html", [
      [ "A. General info", "md_Guides_201_8_01STM32__Code__Structure.html#autotoc_md2", null ],
      [ "B. The STM32 equivalent of setup() and loop() functions found in Arduine IDE", "md_Guides_201_8_01STM32__Code__Structure.html#autotoc_md3", null ],
      [ "C. Global Variables - Declaration, definition and inclusion in the main source code", "md_Guides_201_8_01STM32__Code__Structure.html#autotoc_md4", [
        [ "Global variables should be declared in a <tt>globals.h</tt> file following these steps:", "md_Guides_201_8_01STM32__Code__Structure.html#autotoc_md5", null ],
        [ "The global variables you declared in <tt>globals.h</tt> must be also defined (assigned default values) into a <tt>globals.c</tt> file following these steps:", "md_Guides_201_8_01STM32__Code__Structure.html#autotoc_md6", null ],
        [ "To make your global variables available to the main code, the <tt>globals.h</tt> file must be included into <tt>main.c</tt> file following these steps:", "md_Guides_201_8_01STM32__Code__Structure.html#autotoc_md7", null ]
      ] ],
      [ "D. Creating software module and its local variables", "md_Guides_201_8_01STM32__Code__Structure.html#autotoc_md8", [
        [ "Workflow:", "md_Guides_201_8_01STM32__Code__Structure.html#autotoc_md9", null ],
        [ "The global variables you declared in <tt>globals.h</tt> must be also defined (assigned default values) into a <tt>globals.c</tt> file following these steps:", "md_Guides_201_8_01STM32__Code__Structure.html#autotoc_md10", null ],
        [ "To make your global variables available to the main code, the <tt>globals.h</tt> file must be included into <tt>main.c</tt> file following these steps:", "md_Guides_201_8_01STM32__Code__Structure.html#autotoc_md11", null ],
        [ "To make your global variables available to other source code files, the <tt>globals.h</tt> file must be included into that souce code file following these steps:", "md_Guides_201_8_01STM32__Code__Structure.html#autotoc_md12", null ]
      ] ]
    ] ],
    [ "LCD With I2C", "md_Guides_2LCD__with__I2C.html", [
      [ "Installation", "md_Guides_2LCD__with__I2C.html#autotoc_md14", null ],
      [ "Displaying a formatted string", "md_Guides_2LCD__with__I2C.html#autotoc_md15", null ],
      [ "How do I find the address??", "md_Guides_2LCD__with__I2C.html#autotoc_md16", null ]
    ] ],
    [ "02. Device Configuration Setup Guide", "md_Guides_2Peripheral__Setup.html", [
      [ "Digital Input / Output", "md_Guides_2Peripheral__Setup.html#autotoc_md18", null ],
      [ "Analog Input", "md_Guides_2Peripheral__Setup.html#autotoc_md19", null ],
      [ "PWM Output", "md_Guides_2Peripheral__Setup.html#autotoc_md20", null ],
      [ "Triggering an interrupt on an arbitrary pin", "md_Guides_2Peripheral__Setup.html#autotoc_md21", null ],
      [ "UART Communication", "md_Guides_2Peripheral__Setup.html#autotoc_md22", null ],
      [ "SPI Communication", "md_Guides_2Peripheral__Setup.html#autotoc_md23", null ],
      [ "I2C Communication", "md_Guides_2Peripheral__Setup.html#autotoc_md24", null ],
      [ "Setting a timer interrupt", "md_Guides_2Peripheral__Setup.html#autotoc_md25", null ]
    ] ],
    [ "Timer Clock Guide", "md_Guides_2Timer__Clock.html", [
      [ "APBx Peripheral Clocks", "md_Guides_2Timer__Clock.html#autotoc_md27", null ]
    ] ],
    [ "Using the ADC in DMA mode effectively", "md_Guides_2Using__the__ADC__with__DMA.html", [
      [ "Setup", "md_Guides_2Using__the__ADC__with__DMA.html#autotoc_md29", null ],
      [ "Example usage", "md_Guides_2Using__the__ADC__with__DMA.html#autotoc_md30", null ]
    ] ],
    [ "STM32CubeIDE Debugging Guide", "md_Guides_2Using__the__Debugger.html", [
      [ "Build and Flash the Project", "md_Guides_2Using__the__Debugger.html#autotoc_md33", null ],
      [ "Set Breakpoints", "md_Guides_2Using__the__Debugger.html#autotoc_md34", null ],
      [ "Step Through Code", "md_Guides_2Using__the__Debugger.html#autotoc_md35", null ],
      [ "Inspect Variables", "md_Guides_2Using__the__Debugger.html#autotoc_md37", null ],
      [ "Memory and Registers", "md_Guides_2Using__the__Debugger.html#autotoc_md39", null ],
      [ "Exit Debug Mode", "md_Guides_2Using__the__Debugger.html#autotoc_md41", null ]
    ] ],
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
"annotated.html"
];

var SYNCONMSG = 'click to disable panel synchronisation';
var SYNCOFFMSG = 'click to enable panel synchronisation';