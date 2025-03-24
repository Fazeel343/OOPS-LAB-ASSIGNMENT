#include <iostream>
#include <vector>
using namespace std;

class Account {
    protected:
        int accountNumber;
        double balance;
        string accountHolderName;
        string accountType;
        vector<string> transactionHistory;

    public:
        Account(int accNo, double bal, string name, string type)
            : accountNumber(accNo), balance(bal), accountHolderName(name), accountType(type) {}

        virtual void deposit(double amount) {
            balance += amount;
            transactionHistory.push_back("Deposited: $" + to_string(amount));
            cout << "Deposited: $" << amount << ". New Balance: $" << balance << endl;
        }

        virtual void withdraw(double amount) {
            if (amount > balance) {
                cout << "Insufficient Balance!" << endl;
                return;
            } else {
                balance -= amount;
                transactionHistory.push_back("Withdrawn: $" + to_string(amount));
                cout << "Withdrawn: $" << amount << ". Remaining Balance: $" << balance << endl;
            }
        }

        virtual void calculateInterest() = 0; 

        void printStatement() {
            cout << "\n=== Account Statement ===" << endl;
            cout << "Account No: " << accountNumber << ", Holder: " << accountHolderName << ", Type: " << accountType << endl;
            cout << "Balance: $" << balance << endl;
            cout << "Transaction History:" << endl;
            for (const string &entry : transactionHistory) {
                cout << "- " << entry << endl;
            }
        }
};

class SavingsAccount : public Account {
    private:
        double interestRate;
        double minimumBalance;

    public:
        SavingsAccount(int accNo, double bal, string name, double rate, double minBal)
            : Account(accNo, bal, name, "Savings"), interestRate(rate), minimumBalance(minBal) {}

        void calculateInterest() override {
            double interest = balance * interestRate / 100;
            balance += interest;
            transactionHistory.push_back("Interest Added: $" + to_string(interest));
            cout << "Interest Added: $" << interest << ". New Balance: $" << balance << endl;
        }

        void withdraw(double amount) override {
            if (balance - amount < minimumBalance) {
                cout << "Withdrawal Denied! Minimum Balance Requirement Not Met." << endl;
                return;
            }
            Account::withdraw(amount);
        }
};

class FixedDepositAccount : public Account {
    private:
        double fixedInterestRate;
        int maturityYears;

    public:
        FixedDepositAccount(int accNo, double bal, string name, double rate, int years)
            : Account(accNo, bal, name, "Fixed Deposit"), fixedInterestRate(rate), maturityYears(years) {}

        void calculateInterest() override {
            double interest = balance * (fixedInterestRate / 100) * maturityYears;
            cout << "Fixed Deposit Interest After " << maturityYears << " Years: $" << interest << endl;
        }
};

class CheckingAccount : public Account {
    public:
        CheckingAccount(int accNo, double bal, string name) : Account(accNo, bal, name, "Checking") {}

        void calculateInterest() override {
            cout << "Checking Accounts Do Not Earn Interest." << endl;
        }
};

int main() {

    SavingsAccount sa(263, 12000, "Ali", 6.0, 450);
    CheckingAccount ca(7776, 29000, "Bilal");
    FixedDepositAccount fda(345, 15500, "Ahmad", 4.0, 4);

    sa.deposit(200);
    sa.withdraw(300);
    sa.calculateInterest();
    sa.printStatement();

    ca.withdraw(500);
    ca.calculateInterest();
    ca.printStatement();

    fda.calculateInterest();
    fda.printStatement();

    return 0;
}
