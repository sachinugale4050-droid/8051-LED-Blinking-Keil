# 8051 Password Lock System Using AT89C51

## Project Overview
This project implements a password-based electronic lock system using the AT89C51 microcontroller, a 4×4 keypad, and a 16×2 LCD.

The user enters a four-digit password using the keypad. The LCD displays asterisks instead of the actual password. Pressing `=` checks the password, while `C` clears the entered digits.

## Hardware Components
- AT89C51 Microcontroller
- 4×4 Calculator-Style Keypad
- 16×2 LCD Display (LM016L)
- 11.0592 MHz Crystal
- Resistors and Capacitors
- 5V Power Supply

## Software Tools
- Keil µVision
- Proteus 8 Professional
- Embedded C

## Password
Default password: `1234`

## Working
1. LCD displays "Enter Password".
2. User enters four digits using the keypad.
3. The LCD displays `****` to hide the password.
4. Press `=` to submit the password.
5. If correct, the LCD displays "Unlocked!".
6. If incorrect, the LCD displays "Wrong Password".
7. Press `C` to clear the entered password.

## Project Status
In Progress / Simulation Testing

## Author
Sachin Khandu Ugale

## Repository Contents
- `main.c` – Embedded C source code
- Proteus simulation files
- Keil project files
- `README.md` – Project documentation
