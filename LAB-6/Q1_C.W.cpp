#include <iostream> 
#include <vector>
using namespace std;

class BankAccount {
    protected:
        int accNumber;
        double balance;
    public:
        BankAccount(int accNum, double bal) : accNumber(accNum), balance(bal) {}
        virtual void deposit(double amount) { 
            balance += amount; 
        }
        virtual void withdraw(double amount) {
            balance -= amount;
        }
        virtual void display() {
            cout << "Account: " << accNumber << " | Balance: " << balance << endl;
        }

};

class SavingsAccount : public BankAccount {
    public:
        SavingsAccount(int accNum, double bal) : BankAccount(accNum, bal) {}
        virtual void display() {
            cout << "[Savings] ";
            BankAccount::display(); 
        }
};

class CheckingAccount : public BankAccount {
    public: 
        CheckingAccount(int accNum, double bal) : BankAccount(accNum, bal) {}
        virtual void withdraw(double amount) {
            if (balance - amount <- 500) {
                cout << "Insufficient funds!" << endl;
            }
            else {
                BankAccount::withdraw(amount);
            }
        }
        virtual void display() {
            cout << "[Checking] ";
            BankAccount::display(); 
        }
};

class User {
    protected:
        string name;
    public:
        User(string n) : name(n) {}
        virtual void operate(BankAccount* acc) = 0;
};

class Customer : public User {
    public:
        Customer(string n) : User(n) {}
        virtual void operate(BankAccount* acc) {
            double depositAmount, withdrawAmount;
            cout << name << " , enter deposit amount: ";
            cin >> depositAmount;
            acc -> deposit(depositAmount);
            cout << name << " , enter withdraw amount: ";
            cin >> withdrawAmount;
            acc -> withdraw(withdrawAmount);
            acc -> display();
        }
};

int main() {
    int accNum;
    double balance;
    string customerName;

    cout << "Enter Savings Account Number: ";
    cin >> accNum;
    cout << "Enter Initial Balance: ";
    cin >> balance;
    SavingsAccount sa(accNum, balance);

    cout << "Enter Checking Account Number: ";
    cin  >> accNum;
    cout << "Enter Initial Balance: ";
    cin >> balance;
    CheckingAccount ca(accNum, balance);

    cout << "Enter Customer Name: ";
    cin >> customerName;
    Customer customer(customerName);

    customer.operate(&sa);
    customer.operate(&ca);
    return 0;
}