
# CodeAlfa C++ Virtual Internship Projects

A collection of foundational, intermediate, and advanced C++ console-based software systems completed during the **CodeAlfa Virtual Internship**.

---

## 🎯 Internship Purpose & Objectives

The primary objective of this virtual internship was to apply modern C++ programming paradigms to real-world software engineering scenarios. Across these tasks, emphasis was placed on:

- Writing modular, reusable, and robust code.
- Implementing fundamental algorithmic paradigms like recursive backtracking.
- Applying Object-Oriented Programming (OOP) principles—encapsulation, abstraction, and class hierarchies.
- Managing persistent data storage using file streams (`fstream`) and hashing for security.
- Enhancing command-line user interfaces (CLI) with input validation, animated pacing, and native Windows color attributes (`windows.h`).

---

## 👤 Intern Profile

- **Author:** CodeAlfa Student
- **Organization:** CodeAlfa
- **Role:** C++ Programming Virtual Intern
- **Completion Date:** September 2026

---

## 📋 Task Summaries

### Task 1: CGPA Calculator System
A structured academic management tool that computes individual quality points and cumulative grade point averages (CGPA) on a 4.00 grading scale.
- **Key Concepts:** Structured data types (`struct`), dynamic vector sizing, input validation loops, formatted tabular data (`iomanip`).
- **Visuals:** Console-driven table summary with dynamic status indicators (Green for high standing, Red for warning).

### Task 2: Login and Registration System
A secure, file-backed user authentication module designed to handle user credential lifecycle.
- **Key Concepts:** Delimited file I/O (`users.txt`), duplicate user verification, non-plaintext credential storage via standard hashing (`std::hash`), and input sanitization.
- **Visuals:** Color-coded error and success notifications.

### Task 3: Interactive Sudoku Solver
A visually guided Sudoku puzzle solver utilizing recursive backtracking to resolve standard 9x9 grids against row, column, and $3 \times 3$ subgrid constraints.
- **Key Concepts:** Multidimensional arrays, backtracking algorithms, animated step explanations via typewriter effects, and execution stepping using `_getch()`.
- **Visuals:** Grid coloring distinguishing original clues (yellow), solved digits (green), active cells (magenta), and backtrack traces (red).

### Task 4: Banking Management System
A retail banking management application built upon core Object-Oriented Programming concepts.
- **Key Concepts:** Separation of concerns using `Transaction`, `Account`, `Customer`, and `Bank` classes; double-entry transfer validation; dynamic balance updates; and automated transaction timestamping (`ctime`).
- **Visuals:** Formatted banking statements with chronological ledger tracking and dynamic alert dialogues.

---

## 💻 Tech Stack & Prerequisites

- **Language:** C++ (C++11 standard or later)
- **Platform:** Windows OS (utilizes `<windows.h>` and `<conio.h>`)
- **Recommended Tools:**
  - MinGW / GCC (`g++`)
  - Dev-C++ / Code::Blocks / Visual Studio / VS Code

---

## 🚀 How to Compile and Run

Each task is implemented as a standalone module. Compile and execute them via terminal or an IDE of your choice:

### Via GCC / MinGW Command Line:

```bash
# Task 1: CGPA Calculator
g++ -std=c++11 -o task1_cgpa task1_cgpa.cpp
task1_cgpa.exe

# Task 2: Login and Registration System
g++ -std=c++11 -o task2_auth task2_auth.cpp
task2_auth.exe

# Task 3: Sudoku Solver
g++ -std=c++11 -o task3_sudoku task3_sudoku.cpp
task3_sudoku.exe

# Task 4: Banking Management System
g++ -std=c++11 -o task4_bank task4_bank.cpp
task4_bank.exe

```

### Via IDE (Dev-C++, Code::Blocks, Visual Studio):

1. Open your IDE and create a new C++ Console Project.
2. Replace the main file contents with the corresponding task code.
3. Build and execute using the IDE compile/run shortcut (`F11` in Dev-C++, `F9` in Code::Blocks).

---

## 📜 Copyright & License

© 2026 CodeAlfa Student. All rights reserved.

This repository and its codebase were developed solely for educational and training purposes as part of the CodeAlfa Virtual Internship. Unauthorized redistribution or commercial use without prior permission is strictly prohibited.

```

```
