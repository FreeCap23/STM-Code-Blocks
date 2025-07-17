# STM32CubeIDE Debugging Guide

STM32CubeIDE offers powerful debugging features like breakpoints, variable inspection, memory watch, and step-by-step execution. Here's how to get started.

---

## Build and Flash the Project

Before debugging:

- **Build the project**: Click the **hammer** icon.
- **Flash the code to the board & start debugging**: Click the **green bug** icon (starts debug mode automatically).
![Building and starting the debugger](Media\building_and_debugging_1.png)


## Set Breakpoints

Breakpoints pause the program so you can inspect variables and step through code.

- Click in the **left margin** of your source code (next to the line numbers).
- A **blue dot** appears – this is a breakpoint.
- The program will **pause** when it reaches this line.


## Step Through Code

After the code pauses (e.g., at a breakpoint), you can control execution:

| Button            | Function                                |
| ----------------- | --------------------------------------- |
| 🔄 Stop and Rerun | Stop current session and start again    |
| ▶ Resume          | Continue running the program            |
| ⏸ Pause           | Pause execution at the current location |
| ⏹ Stop            | Terminate the debug session             |
| 🔌 Disconnect     | Detach debugger without stopping target |
| ⏬ Step Into       | Enter a function being called           |
| ⏭ Step Over       | Run next line, skipping into functions  |
| ⏩ Step Return     | Run until current function finishes     |

These buttons are in the **Debug toolbar**.
![Buttons for stepping through code](Media\debugger_code_stepping.png)

---

## Inspect Variables

- Go to the **Variables** tab.
- View or hover over variables to see their current values.
- Local and global variables are listed automatically.

You can also:

- Right-click a variable and **Add to Expressions**.
- Use **Watch** or **Expressions** tabs to track custom variables.
- Use the **Live Expressions** tab to see values update in real-time.

---

## Memory and Registers

- Use **Memory** view to inspect specific memory addresses (e.g., for arrays or peripherals).
- Use **Registers** view to see CPU and peripheral register states (advanced use).

---

## Exit Debug Mode

- Click the **red square** to stop the debug session.
- STM32CubeIDE will prompt to return to **C/C++ Perspective** (click Yes).