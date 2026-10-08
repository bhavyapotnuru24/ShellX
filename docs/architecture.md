# ShellX Architecture

ShellX is a modular Linux toolkit developed in C.

The main.c file acts as the central controller of the application.
It displays the main menu and calls the required module based
on the user's choice.

## Major Modules

- File Manager
- Command Runner
- Notes Manager
- Calculator
- System Information
- Password Generator

## Supporting Components

- UI utilities
- Logger
- Validator
- Data files
- Makefile

## Architecture Flow

User
  ↓
Main Menu
  ↓
Selected Module
  ↓
Linux / File System
  ↓
Output
