# Login and Registration System (C++)

**Virtual Internship Task - 2**  
**Organization:** CodeAlfa  
**Domain:** C++ Programming  
**Author:** CodeAlfa Student    

---

## 📌 Project Overview

The **Login and Registration System** is a secure, console-based authentication application implemented in C++. It allows new users to create accounts with unique credentials, securely stores these records using password hashing and persistent file storage, and authenticates returning users via a dedicated login portal. 

The application utilizes the Windows Console API (`windows.h`) to deliver interactive color-coded status alerts, user prompts, and structured navigation menus.

---

## ✨ Features

- **User Registration:**
  - Dynamic user creation with custom usernames and passwords.
  - Duplicate username check preventing account collisions.
  - Length and illegal-character validation (e.g., prohibiting delimiter conflicts).
- **Secure Credential Storage:**
  - File persistence via standard file streams (`users.txt`).
  - Passwords are encrypted/hashed (`std::hash`) prior to storage to prevent plain-text exposure.
- **User Authentication (Login):**
  - Reads stored records and matches the hashed input against saved credentials.
  - Dynamic status checks with distinct error and success feedback.
- **Robust Input Handling:**
  - Numeric validation for menu navigation to handle invalid stream inputs gracefully.
- **Visual Console Styling:**
  - Color-coded prompts using native Windows console attributes (Success: Green, Errors: Red, Prompts: Cyan/Yellow).

---

## 🔐 Security & Data Flow

1. **Input Submission:** User enters username and password in the console.
2. **Pre-Processing:** Password undergoes a hash generation step via standard hashing functions:
   $$\text{Stored Value} = \text{Hash}(\text{Input Password})$$
3. **Storage Format:** Credentials are saved in CSV format (`username,hashed_password`) inside `users.txt`.
4. **Verification:** During login, the entered password is independently hashed and matched against the file entry for that username.

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
g++ -o loginRegistrationSystem.cpp

# Run the executable
loginRegistrationSystem.exe

```

### 2. Using an IDE (Dev-C++ / Code::Blocks / Visual Studio):

1. Open your IDE and create a new C++ console project.
2. Paste the source code into `main.cpp`.
3. Click **Build & Run** (or press `F11` / `F9` depending on your IDE).

---

## 👤 Author

* **Name:** CodeAlfa Student  
* **Internship:** CodeAlfa C++ Virtual Internship
* **Task:** Task 1 – Login/Registration System

```

```
