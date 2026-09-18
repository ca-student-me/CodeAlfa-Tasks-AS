#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

void setColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}

// Simple hash function to avoid storing passwords in plain text
string hashPassword(const string& password) {
    hash<string> hasher;
    return to_string(hasher(password));
}

// Check if username already exists in database
bool isUserExists(const string& username) {
    ifstream file("users.txt");
    if (!file.is_open()) {
        return false;
    }

    string line, storedUser, storedHash;
    while (getline(file, line)) {
        stringstream ss(line);
        if (getline(ss, storedUser, ',') && getline(ss, storedHash)) {
            if (storedUser == username) {
                file.close();
                return true;
            }
        }
    }
    file.close();
    return false;
}

// User Registration
void registerUser() {
    string username, password;

    setColor(13); // Magenta
    cout << "\n---------------- USER REGISTRATION ----------------\n";
    
    setColor(11); // Cyan
    cout << "Enter username: ";
    setColor(15);
    cin >> username;

    // Validate username input
    if (username.length() < 3) {
        setColor(12); // Red
        cout << "[ERROR] Username must be at least 3 characters long.\n";
        setColor(7);
        return;
    }

    if (username.find(',') != string::npos) {
        setColor(12);
        cout << "[ERROR] Username cannot contain commas.\n";
        setColor(7);
        return;
    }

    if (isUserExists(username)) {
        setColor(12);
        cout << "[ERROR] Username already taken! Please choose another.\n";
        setColor(7);
        return;
    }

    setColor(11);
    cout << "Enter password: ";
    setColor(15);
    cin >> password;

    // Validate password input
    if (password.length() < 6) {
        setColor(12);
        cout << "[ERROR] Password must be at least 6 characters long.\n";
        setColor(7);
        return;
    }

    // Save credentials to database file
    ofstream file("users.txt", ios::app);
    if (!file.is_open()) {
        setColor(12);
        cout << "[ERROR] Unable to access database file.\n";
        setColor(7);
        return;
    }

    file << username << "," << hashPassword(password) << "\n";
    file.close();

    setColor(10); // Green
    cout << "[SUCCESS] Account registered successfully!\n";
    setColor(7);
}

// User Login
void loginUser() {
    string username, password;

    setColor(13); // Magenta
    cout << "\n------------------- USER LOGIN -------------------\n";

    setColor(11); // Cyan
    cout << "Enter username: ";
    setColor(15);
    cin >> username;

    setColor(11);
    cout << "Enter password: ";
    setColor(15);
    cin >> password;

    ifstream file("users.txt");
    if (!file.is_open()) {
        setColor(12); // Red
        cout << "[ERROR] No registered users found in the system.\n";
        setColor(7);
        return;
    }

    string line, storedUser, storedHash;
    string inputHash = hashPassword(password);
    bool loginSuccess = false;

    while (getline(file, line)) {
        stringstream ss(line);
        if (getline(ss, storedUser, ',') && getline(ss, storedHash)) {
            if (storedUser == username && storedHash == inputHash) {
                loginSuccess = true;
                break;
            }
        }
    }
    file.close();

    if (loginSuccess) {
        setColor(10); // Green
        cout << "[SUCCESS] Welcome back, " << username << "! Login successful.\n";
    } else {
        setColor(12); // Red
        cout << "[ERROR] Invalid username or password.\n";
    }
    setColor(7);
}

int main() {
    int choice;

    while (true) {
        setColor(11); // Cyan
        cout << "\n===================================================\n";
        cout << "           LOGIN & REGISTRATION SYSTEM             \n";
        cout << "===================================================\n";
        
        setColor(14); // Yellow
        cout << "1. Register New Account\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        
        setColor(11);
        cout << "Select an option (1-3): ";
        setColor(15);
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            setColor(12);
            cout << "[ERROR] Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                setColor(10);
                cout << "\nExiting application. Goodbye!\n";
                setColor(7);
                return 0;
            default:
                setColor(12);
                cout << "[ERROR] Invalid choice. Select 1, 2, or 3.\n";
                setColor(7);
        }
    }

    return 0;
}