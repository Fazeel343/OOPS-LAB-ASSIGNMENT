#include <iostream>
using namespace std;

class Account {
    private:
        double balance; 

    public:
        Account(double initialBalance) {
            if (initialBalance < 0) {
                cout << "Invalid Initial Balance. Setting Balance to 0.\n";
                balance = 0;
            } else {
                balance = initialBalance;
            }
        }

        void credit(double amount) {
            if (amount > 0) {
                balance += amount;
                cout << "Credited: " << amount << "\n";
            } else {
                cout << "Invalid Credit Amount!\n";
            }
        }

        void debit(double amount) {
            if (amount > balance) {
                cout << "Debit Amount Exceeded Account Balance!\n";
            } else if (amount > 0) {
                balance -= amount;
                cout << "Debited: " << amount << "\n";
            } else {
                cout << "Invalid Debit Amount!\n";
            }
        }

        double getBalance() {
            return balance;
        }
};

int main() {
    double initialAmount, creditAmount, debitAmount;
    cout << "Enter Initial Account Balance: ";
    cin >> initialAmount;
    Account myAccount(initialAmount);

    cout << "Enter Amount To Deposit: ";
    cin >> creditAmount;
    myAccount.credit(creditAmount);

    cout << "Enter Amount To Withdraw: ";
    cin >> debitAmount;
    myAccount.debit(debitAmount);

    cout << "Your Remaining Balance is: " << myAccount.getBalance() << "\n";

    return 0;
}
