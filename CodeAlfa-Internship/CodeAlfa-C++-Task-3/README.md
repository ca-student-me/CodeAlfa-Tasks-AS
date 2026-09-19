# Interactive Sudoku Solver (C++)

**Virtual Internship Task - 3**  
**Organization:** CodeAlfa  
**Domain:** C++ Programming  
**Author:** CodeAlfa Student 

---

## 📌 Project Overview

The **Interactive Sudoku Solver** is a console-based C++ application designed to solve standard 9x9 Sudoku puzzles using recursive backtracking. Unlike standard black-box solvers, this program provides a step-by-step visual execution flow. It prints the board state in real time, uses an animated typewriter effect to describe each algorithmic action, highlights modifications, and pauses execution using `_getch()` so each placement and backtrack can be observed interactively.

---

## ✨ Features

- **Backtracking Algorithm:** Automatically finds and resolves empty cells while adhering strictly to row, column, and $3 \times 3$ subgrid constraints.
- **Step-by-Step Visualization:**
  - Displays each decision: placing candidate numbers and backtracking upon dead ends.
  - Interactive pacing controlled via keyboard input (`_getch()`).
  - Animated console output with simulated typing pauses (`Sleep()`).
- **Dynamic Color Highlighting (Windows Console API):**
  - 🟡 **Yellow:** Original clue numbers (fixed).
  - 🟢 **Green:** Successfully placed and solved numbers.
  - 🟣 **Magenta:** Active cell currently being modified or tested.
  - ⚪ **Dark Gray (`.`):** Empty puzzle cells.
  - 🔴 **Red:** Backtrack alerts and invalid entry notifications.
- **Dual Execution Modes:**
  - **Demo Mode:** Uses a near-complete board to quickly demonstrate valid placements, backtracking triggers, and solution convergence without thousands of keypresses.
  - **Full Puzzle Mode:** Solves a standard 9x9 puzzle from scratch.

---

## 🧩 Algorithm & Constraints

A number $D \in \{1, \dots, 9\}$ is valid at cell $(R, C)$ if and only if:

1. **Row Constraint:** $D$ does not appear in row $R$:
   $$\forall j \in \{0, \dots, 8\}, \quad \text{board}[R][j] \neq D$$
2. **Column Constraint:** $D$ does not appear in column $C$:
   $$\forall i \in \{0, \dots, 8\}, \quad \text{board}[i][C] \neq D$$
3. **Subgrid Constraint:** $D$ does not appear in the $3 \times 3$ subgrid containing $(R, C)$:
   $$\forall r \in \{0, 1, 2\}, \forall c \in \{0, 1, 2\}, \quad \text{board}\left[\lfloor R / 3 \rfloor \times 3 + r\right]\left[\lfloor C / 3 \rfloor \times 3 + c\right] \neq D$$

If no valid candidate exists for an empty cell, the algorithm triggers a **backtrack**, resetting the cell to `0` and returning to the previous recursive frame.

---

## 💻 Tech Stack & Requirements

- **Language:** C++ (C++11 or later)
- **Operating System:** Windows (relies on `<windows.h>` and `<conio.h>` for console styling and input pausing)
- **Supported IDEs / Compilers:**
  - MinGW / GCC (`g++`)
  - Dev-C++
  - Code::Blocks
  - Visual Studio / VS Code with MinGW

## 🚀 How to Compile & Run

### 1. Using GCC / MinGW via Command Line:
```bash
# Compile the program
g++ -o sudoku_solver main.cpp

# Run the executable
sudoku_solver.exe
```
### 2. Using an IDE (Dev-C++ / Code::Blocks / Visual Studio):

1. Open your IDE and create a new C++ console project.
2. Paste the source code into `main.cpp`.
3. Click **Build & Run** (or press `F11` / `F9` depending on your IDE).

---

## 👤 Author

* **Name:** CodeAlfa Student  
* **Internship:** CodeAlfa C++ Virtual Internship
* **Task:** Task 3 – Sudoku Solver

```

```
