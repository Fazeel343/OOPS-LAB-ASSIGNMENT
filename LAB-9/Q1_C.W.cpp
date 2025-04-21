#include <iostream>
#include <string>
using namespace std;

class Wallet {
private:
    double balance;
    double dailyDepositLimit;
    double dailyWithdrawLimit;
    double todayDeposited;
    double todayWithdrawn;

public:
    Wallet() : balance(0), dailyDepositLimit(10000), dailyWithdrawLimit(5000), todayDeposited(0), todayWithdrawn(0) {}

    bool deposit(double amount) {
        if (amount <= 0 || (todayDeposited + amount > dailyDepositLimit)) {
            cout << "Deposit failed: Limit exceeded or invalid amount.\n";
            return false;
        }
        balance += amount;
        todayDeposited += amount;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance || (todayWithdrawn + amount > dailyWithdrawLimit)) {
            cout << "Withdrawal failed: Insufficient balance or limit exceeded.\n";
            return false;
        }
        balance -= amount;
        todayWithdrawn += amount;
        return true;
    }

    double getBalance() const {
        return balance;
    }
};

class User {
private:
    string userID;
    string name;
    Wallet wallet;

public:
    User(string id, string nm) : userID(id), name(nm) {}

    void deposit(double amount) {
        wallet.deposit(amount);
    }

    void withdraw(double amount) {
        wallet.withdraw(amount);
    }

    void checkBalance() const {
        cout << name << "'s Balance: " << wallet.getBalance() << endl;
    }
};

int main() {
    User u1("101", "Ali");
    u1.deposit(5000);
    u1.withdraw(1000);
    u1.checkBalance();

    User u2("102", "Sara");
    u2.deposit(12000); // should fail
    u2.withdraw(6000); // should fail
    u2.checkBalance();

    return 0;
}
