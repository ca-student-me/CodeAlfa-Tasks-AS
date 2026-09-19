# Banking Management System (C++)

**Virtual Internship Task - 4**  
**Organization:** CodeAlfa  
**Domain:** C++ Programming  
**Author:** Syed Muhammad Sajawal Hussain  

---

## 📌 Project Overview

The **Banking Management System** is an Object-Oriented Programming (OOP) console application written in C++. It simulates core retail banking operations, enabling the management of customer entities, accounts, and monetary transactions. 

The architecture adheres to core OOP principles (Encapsulation, Modular Abstraction, and Separation of Concerns) through distinct `Transaction`, `Account`, `Customer`, and `Bank` classes. Real-time balance calculations, input validations, automated timestamps, and color-coded status reporting via the Windows Console API (`windows.h`) are integrated throughout.

---

## ✨ Features

- **Customer Management:**
  - Create and register customer profiles with auto-incremented Customer IDs.
  - Link multiple accounts to a single customer profile.
- **Account Operations:**
  - Open new accounts with custom initial deposit thresholds.
  - Cash deposit and withdrawal handling with overdraft prevention.
  - Direct account-to-account funds transfer with dual-entry ledger updates.
- **Transaction History & Auditing:**
  - Each financial operation automatically instantiates a timestamped `Transaction` record.
  - Formatted tabular statements displaying Date/Time, Transaction Type, Amount, and Post-Transaction Balance.
- **Visual Console Interface:**
  - Distinct color-coded prompts and alerts (Green for success, Red for errors, Cyan/Yellow for menus and tables).

---

## 🏗️ Class Architecture & Design

- **`Transaction`**: Encapsulates transaction metadata, including system timestamps (`time.h`), transaction type (Deposit, Withdrawal, Transfer In/Out), amount, and post-transaction balance.
- **`Account`**: Maintains account number, current balance, and a ledger vector (`std::vector<Transaction>`). Encapsulates core balance modification logic.
- **`Customer`**: Holds personal details (ID, Name, Contact) and a collection of owned `Account` objects.
- **`Bank`**: Central controller class handling data storage, ID generation, account lookups, and transaction coordination.

---

## 💻 Tech Stack & Requirements

- **Language:** C++ (C++11 or later)
- **Operating System:** Windows (utilizes `<windows.h>` for console styling)
- **Supported Compilers & IDEs:**
  - MinGW / GCC (`g++`)
  - Dev-C++
  - Code::Blocks
  - Visual Studio / VS Code with MinGW / MSVC

---

## 🚀 How to Compile & Run

### 1. Using GCC / MinGW via Command Line:
```bash
# Compile the code
g++ -std=c++11 -o bank_system main.cpp

# Run the executable
bank_system.exe
```


### 2. Using an IDE (Dev-C++ / Code::Blocks / Visual Studio):

1. Open your IDE and create a new C++ console project.
2. Paste the source code into `main.cpp`.
3. Click **Build & Run** (or press `F11` / `F9` depending on your IDE).

---

## 👤 Author

* **Name:** CodeAlfa Student  
* **Internship:** CodeAlfa C++ Virtual Internship
* **Task:** Task 4 – Banking Management System

```

