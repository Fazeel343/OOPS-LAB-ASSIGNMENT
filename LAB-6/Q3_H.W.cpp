#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    double balance;

public:
    BankAccount(int accNum, double bal) : accountNumber(accNum), balance(bal) {}
    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " New Balance: " << balance << endl;
    }
    virtual void withdraw(double amount) {
        if (amount > balance)
            cout << "Insufficient funds!" << endl;
        else {
            balance -= amount;
            cout << "Withdrawn: " << amount << " New Balance: " << balance << endl;
        }
    }
    virtual void display() {
        cout << "Account " << accountNumber << " Balance: " << balance << endl;
    }
    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
    double interestRate;
public:
    SavingsAccount(int accNum, double bal, double rate) : BankAccount(accNum, bal), interestRate(rate) {}
    void applyInterest() {
        balance += balance * (interestRate / 100);
        cout << "Interest applied. New Balance: " << balance << endl;
    }
    void display() override {
        cout << "Savings Account " << accountNumber << " Balance: " << balance << " Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public BankAccount {
    double overdraftLimit;
public:
    CheckingAccount(int accNum, double bal, double limit) : BankAccount(accNum, bal), overdraftLimit(limit) {}
    void withdraw(double amount) override {
        if (amount > balance + overdraftLimit)
            cout << "Overdraft limit exceeded!" << endl;
        else {
            balance -= amount;
            cout << "Withdrawn: " << amount << " New Balance: " << balance << endl;
        }
    }
    void display() override {
        cout << "Checking Account " << accountNumber << " Balance: " << balance << " Overdraft Limit: " << overdraftLimit << endl;
    }
};

class BusinessAccount : public BankAccount {
    double taxRate;
public:
    BusinessAccount(int accNum, double bal, double tax) : BankAccount(accNum, bal), taxRate(tax) {}
    void deposit(double amount) override {
        double taxedAmount = amount - (amount * taxRate / 100);
        balance += taxedAmount;
        cout << "Deposited after tax: " << taxedAmount << " New Balance: " << balance << endl;
    }
    void display() override {
        cout << "Business Account " << accountNumber << " Balance: " << balance << " Corporate Tax: " << taxRate << "%" << endl;
    }
};

class Employee {
public:
    virtual void performAction(BankAccount* account) = 0;
};

class Customer : public Employee {
public:
    void performAction(BankAccount* account) override {
        double amount;
        cout << "Enter deposit amount: ";
        cin >> amount;
        account->deposit(amount);
        cout << "Enter withdrawal amount: ";
        cin >> amount;
        account->withdraw(amount);
    }
};

class Teller : public Employee {
public:
    void performAction(BankAccount* account) override {
        double amount;
        cout << "Teller processing deposit: ";
        cin >> amount;
        account->deposit(amount);
    }
};

class Manager : public Employee {
public:
    void performAction(BankAccount* account) override {
        cout << "Manager reviewing account details." << endl;
        account->display();
    }
};

int main() {
    vector<BankAccount*> accounts = {
        new SavingsAccount(1001, 5000, 5),
        new CheckingAccount(1002, 2000, 500),
        new BusinessAccount(1003, 10000, 10)
    };
    
    vector<Employee*> employees = { new Customer(), new Teller(), new Manager() };
    
    for (auto emp : employees) {
        cout << "Performing employee actions...\n";
        for (auto acc : accounts) emp->performAction(acc);
        cout << "----------------------\n";
    }
    
    for (auto acc : accounts) delete acc;
    for (auto emp : employees) delete emp;
    return 0;
}
