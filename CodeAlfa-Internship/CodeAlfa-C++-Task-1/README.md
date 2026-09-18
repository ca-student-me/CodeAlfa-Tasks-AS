
# CGPA Calculator System (C++)

**Virtual Internship Task - 1**  
**Organization:** CodeAlfa  
**Domain:** C++ Programming  
**Author:** Syed Muhammad Sajawal Hussain  

---

## 📌 Project Overview

The **CGPA Calculator System** is a console-based application developed in C++ designed to streamline and automate the academic grading and CGPA computation process. It accepts semester course details including course identifiers, letter grades, and credit hours and dynamically computes both individual course quality points and the student's cumulative grade point average (CGPA) on a 4.00 grading scale.

The interface includes native Windows console color-coding (`windows.h`) to deliver a clear, structured, and visually engaging command-line user experience.

---

## ✨ Features

- **Dynamic Course Handling:** Prompts the user for any number of enrolled courses.
- **Grade-to-Point Conversion:** Automatically maps standard letter grades (`A`, `B`, `C`, `D`, `F`) to standard 4.0 scale grade points.
- **Input Validation:** Validates course count, grade letters, and credit hours, prompting the user until valid inputs are provided.
- **Detailed Academic Summary:** Presents formatted, tabular output showing:
  - Course Name / Code
  - Grade Points
  - Credit Hours
  - Earned Quality Points (Grade Points × Credit Hours)
- **Cumulative Calculations:** Displays total semester credit hours, total quality points, and overall final CGPA.
- **Visual Status Color Indicators:**
  - 🟢 **Green:** CGPA ≥ 3.00 (Distinction / Good Standing)
  - 🟡 **Yellow:** 2.00 ≤ CGPA < 3.00 (Satisfactory)
  - 🔴 **Red:** CGPA < 2.00 (Academic Alert / Probation)
- **Enhanced Console Styling:** Styled tables, banners, and text highlights using Windows Console API attributes.

---

## 📊 Grading Scale Reference

| Letter Grade | Grade Point Value | Status / Description |
|:------------:|:-----------------:|:--------------------|
| **A**        | 4.00              | Excellent           |
| **B**        | 3.00              | Good                |
| **C**        | 2.00              | Average             |
| **D**        | 1.00              | Pass                |
| **F**        | 0.00              | Fail                |

$$\text{Quality Points} = \text{Grade Points} \times \text{Credit Hours}$$

$$\text{CGPA} = \frac{\sum (\text{Grade Points} \times \text{Credit Hours})}{\sum \text{Credit Hours}}$$

---

## 💻 Tech Stack & Requirements

- **Language:** C++ (C++11 or later recommended)
- **Operating System:** Windows (utilizes `<windows.h>` for console styling)
- **Supported IDEs / Compilers:**
  - MinGW / GCC (`g++`)
  - Dev-C++
  - Code::Blocks
  - Visual Studio / VS Code with MSVC or MinGW

---

## 🚀 How to Compile & Run

### 1. Using GCC / MinGW via Command Line:
```bash
# Compile the source code
g++ -o cgpa_calculator main.cpp

# Run the executable
cgpa_calculator.exe

```

### 2. Using an IDE (Dev-C++ / Code::Blocks / Visual Studio):

1. Open your IDE and create a new C++ console project.
2. Paste the source code into `main.cpp`.
3. Click **Build & Run** (or press `F11` / `F9` depending on your IDE).

---

## 👤 Author

* **Name:** Syed Muhammad Sajawal Hussain
* **Internship:** CodeAlfa C++ Virtual Internship
* **Task:** Task 1 – CGPA Calculator

```

```
