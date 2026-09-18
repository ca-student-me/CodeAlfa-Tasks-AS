#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <windows.h>
#include <ctime>

using namespace std;

void setColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}

string getCurrentTimestamp() {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);
    char buffer[30];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &ltm);
    return string(buffer);
}

class Transaction {
private:
    string type;
    double amount;
    double balanceAfter;
    string timestamp;

public:
    Transaction(string t, double amt, double bal) 
        : type(t), amount(amt), balanceAfter(bal), timestamp(getCurrentTimestamp()) {}

    void display() const {
        setColor(15);
        cout << left << setw(22) << timestamp
             << setw(16) << type
             << "$" << setw(14) << fixed << setprecision(2) << amount
             << "$" << fixed << setprecision(2) << balanceAfter << endl;
    }
};

class Account {
private:
    int accountNumber;
    double balance;
    vector<Transaction> history;

public:
    Account(int accNo, double initBalance = 0.0) 
        : accountNumber(accNo), balance(initBalance) {
        if (initBalance > 0) {
            history.push_back(Transaction("Initial Deposit", initBalance, balance));
        }
    }

    int getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }

    bool deposit(double amount) {
        if (amount <= 0) return false;
        balance += amount;
        history.push_back(Transaction("Deposit", amount, balance));
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) return false;
        balance -= amount;
        history.push_back(Transaction("Withdrawal", amount, balance));
        return true;
    }

    bool transferOut(double amount, int targetAccNo) {
        if (amount <= 0 || amount > balance) return false;
        balance -= amount;
        history.push_back(Transaction("Transfer Out (" + to_string(targetAccNo) + ")", amount, balance));
        return true;
    }

    void transferIn(double amount, int sourceAccNo) {
        balance += amount;
        history.push_back(Transaction("Transfer In (" + to_string(sourceAccNo) + ")", amount, balance));
    }

    void displayTransactions() const {
        if (history.empty()) {
            setColor(12);
            cout << "No past transactions recorded for this account.\n";
            setColor(7);
            return;
        }

        setColor(9);
        cout << "----------------------------------------------------------------------\n";
        setColor(14);
        cout << left << setw(22) << "Date & Time" 
             << setw(16) << "Type" 
             << setw(15) << "Amount" 
             << "Balance After" << endl;
        setColor(9);
        cout << "----------------------------------------------------------------------\n";

        for (const auto& txn : history) {
            txn.display();
        }
        setColor(9);
        cout << "----------------------------------------------------------------------\n";
        setColor(7);
    }
};

class Customer {
private:
    int customerId;
    string name;
    string contact;
    vector<Account> accounts;

public:
    Customer(int id, string n, string c) : customerId(id), name(n), contact(c) {}

    int getId() const { return customerId; }
    string getName() const { return name; }

    void addAccount(int accNo, double initialBalance) {
        accounts.emplace_back(accNo, initialBalance);
    }

    Account* getAccount(int accNo) {
        for (auto& acc : accounts) {
            if (acc.getAccountNumber() == accNo) return &acc;
        }
        return nullptr;
    }

    void displayCustomerInfo() const {
        setColor(11);
        cout << "\nCustomer ID : "; setColor(15); cout << customerId << endl;
        setColor(11);
        cout << "Name        : "; setColor(15); cout << name << endl;
        setColor(11);
        cout << "Contact     : "; setColor(15); cout << contact << endl;
        setColor(11);
        cout << "Accounts    : "; setColor(14); cout << accounts.size() << " registered account(s)\n";

        setColor(9);
        cout << "----------------------------------------------\n";
        setColor(13);
        cout << left << setw(20) << "Account Number" << "Current Balance" << endl;
        setColor(9);
        cout << "----------------------------------------------\n";
        for (const auto& acc : accounts) {
            setColor(15);
            cout << left << setw(20) << acc.getAccountNumber()
                 << "$" << fixed << setprecision(2) << acc.getBalance() << endl;
        }
        setColor(9);
        cout << "----------------------------------------------\n";
        setColor(7);
    }
};

class Bank {
private:
    vector<Customer> customers;
    int nextCustomerId = 1001;
    int nextAccountNumber = 50001;

public:
    Customer* findCustomer(int custId) {
        for (auto& cust : customers) {
            if (cust.getId() == custId) return &cust;
        }
        return nullptr;
    }

    Account* findAccount(int accNo) {
        for (auto& cust : customers) {
            Account* acc = cust.getAccount(accNo);
            if (acc != nullptr) return acc;
        }
        return nullptr;
    }

    void createCustomer() {
        string name, contact;
        setColor(13);
        cout << "\n--- CREATE NEW CUSTOMER ---\n";
        setColor(11);
        cout << "Enter Customer Full Name: ";
        setColor(15);
        cin.ignore();
        getline(cin, name);

        setColor(11);
        cout << "Enter Phone / Email: ";
        setColor(15);
        getline(cin, contact);

        customers.emplace_back(nextCustomerId, name, contact);
        setColor(10);
        cout << "[SUCCESS] Customer created successfully! Assigned Customer ID: " << nextCustomerId << endl;
        nextCustomerId++;
        setColor(7);
    }

    void openAccount() {
        int custId;
        double initialDeposit;

        setColor(13);
        cout << "\n--- OPEN NEW BANK ACCOUNT ---\n";
        setColor(11);
        cout << "Enter Customer ID: ";
        setColor(15);
        cin >> custId;

        Customer* cust = findCustomer(custId);
        if (!cust) {
            setColor(12);
            cout << "[ERROR] Customer with ID " << custId << " does not exist.\n";
            setColor(7);
            return;
        }

        setColor(11);
        cout << "Enter Initial Deposit Amount: $";
        setColor(15);
        cin >> initialDeposit;

        if (initialDeposit < 0) {
            setColor(12);
            cout << "[ERROR] Initial deposit cannot be negative.\n";
            setColor(7);
            return;
        }

        cust->addAccount(nextAccountNumber, initialDeposit);
        setColor(10);
        cout << "[SUCCESS] Account opened successfully! Account Number: " << nextAccountNumber << endl;
        nextAccountNumber++;
        setColor(7);
    }

    void handleDeposit() {
        int accNo;
        double amount;
        setColor(13);
        cout << "\n--- DEPOSIT FUNDS ---\n";
        setColor(11); cout << "Enter Account Number: "; setColor(15); cin >> accNo;

        Account* acc = findAccount(accNo);
        if (!acc) {
            setColor(12); cout << "[ERROR] Account not found.\n"; setColor(7); return;
        }

        setColor(11); cout << "Enter Deposit Amount: $"; setColor(15); cin >> amount;
        if (acc->deposit(amount)) {
            setColor(10);
            cout << "[SUCCESS] Deposited $" << fixed << setprecision(2) << amount 
                 << ". New Balance: $" << acc->getBalance() << endl;
        } else {
            setColor(12); cout << "[ERROR] Deposit amount must be greater than zero.\n";
        }
        setColor(7);
    }

    void handleWithdrawal() {
        int accNo;
        double amount;
        setColor(13);
        cout << "\n--- WITHDRAW FUNDS ---\n";
        setColor(11); cout << "Enter Account Number: "; setColor(15); cin >> accNo;

        Account* acc = findAccount(accNo);
        if (!acc) {
            setColor(12); cout << "[ERROR] Account not found.\n"; setColor(7); return;
        }

        setColor(11); cout << "Enter Withdrawal Amount: $"; setColor(15); cin >> amount;
        if (acc->withdraw(amount)) {
            setColor(10);
            cout << "[SUCCESS] Withdrawn $" << fixed << setprecision(2) << amount 
                 << ". New Balance: $" << acc->getBalance() << endl;
        } else {
            setColor(12); cout << "[ERROR] Insufficient funds or invalid amount.\n";
        }
        setColor(7);
    }

    void handleTransfer() {
        int fromAccNo, toAccNo;
        double amount;
        setColor(13);
        cout << "\n--- FUND TRANSFER ---\n";
        setColor(11); cout << "Enter Source Account Number: "; setColor(15); cin >> fromAccNo;
        setColor(11); cout << "Enter Destination Account Number: "; setColor(15); cin >> toAccNo;

        if (fromAccNo == toAccNo) {
            setColor(12); cout << "[ERROR] Cannot transfer funds to the same account.\n"; setColor(7); return;
        }

        Account* fromAcc = findAccount(fromAccNo);
        Account* toAcc = findAccount(toAccNo);

        if (!fromAcc || !toAcc) {
            setColor(12); cout << "[ERROR] One or both accounts do not exist.\n"; setColor(7); return;
        }

        setColor(11); cout << "Enter Amount to Transfer: $"; setColor(15); cin >> amount;

        if (fromAcc->transferOut(amount, toAccNo)) {
            toAcc->transferIn(amount, fromAccNo);
            setColor(10);
            cout << "[SUCCESS] Transferred $" << fixed << setprecision(2) << amount 
                 << " to Account " << toAccNo << ".\n";
            cout << "Remaining Balance in Account " << fromAccNo << ": $" << fromAcc->getBalance() << endl;
        } else {
            setColor(12); cout << "[ERROR] Transfer failed: Insufficient balance or invalid amount.\n";
        }
        setColor(7);
    }

    void viewCustomerSummary() {
        int custId;
        setColor(13);
        cout << "\n--- VIEW CUSTOMER DETAILS ---\n";
        setColor(11); cout << "Enter Customer ID: "; setColor(15); cin >> custId;

        Customer* cust = findCustomer(custId);
        if (cust) {
            cust->displayCustomerInfo();
        } else {
            setColor(12); cout << "[ERROR] Customer ID not found.\n"; setColor(7);
        }
    }

    void viewAccountHistory() {
        int accNo;
        setColor(13);
        cout << "\n--- VIEW TRANSACTION HISTORY ---\n";
        setColor(11); cout << "Enter Account Number: "; setColor(15); cin >> accNo;

        Account* acc = findAccount(accNo);
        if (acc) {
            setColor(14);
            cout << "\nTransaction Statement for Account: " << accNo 
                 << " | Current Balance: $" << fixed << setprecision(2) << acc->getBalance() << endl;
            acc->displayTransactions();
        } else {
            setColor(12); cout << "[ERROR] Account not found.\n"; setColor(7);
        }
    }
};

int main() {
    Bank bank;
    int choice;

    while (true) {
        setColor(11);
        cout << "\n======================================================\n";
        cout << "              BANKING MANAGEMENT SYSTEM               \n";
        cout << "======================================================\n";
        setColor(14);
        cout << "1. Register Customer\n";
        cout << "2. Open New Bank Account\n";
        cout << "3. Deposit Funds\n";
        cout << "4. Withdraw Funds\n";
        cout << "5. Transfer Funds\n";
        cout << "6. View Customer Details & Balances\n";
        cout << "7. View Account Transaction Statement\n";
        cout << "8. Exit System\n";
        setColor(11);
        cout << "Enter choice (1-8): ";
        setColor(15);

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            setColor(12);
            cout << "[ERROR] Invalid input. Please enter a valid number.\n";
            continue;
        }

        switch (choice) {
            case 1: bank.createCustomer(); break;
            case 2: bank.openAccount(); break;
            case 3: bank.handleDeposit(); break;
            case 4: bank.handleWithdrawal(); break;
            case 5: bank.handleTransfer(); break;
            case 6: bank.viewCustomerSummary(); break;
            case 7: bank.viewAccountHistory(); break;
            case 8:
                setColor(10);
                cout << "\nThank you for using the Banking Management System. Goodbye!\n";
                setColor(7);
                return 0;
            default:
                setColor(12);
                cout << "[ERROR] Invalid choice. Choose between 1 and 8.\n";
                setColor(7);
        }
    }

    return 0;
}