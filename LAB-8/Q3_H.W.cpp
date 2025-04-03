#include <iostream>
using namespace std;

class Person {
    protected:
        int empID;

    public:
        void getData() {
            cout << "Enter Employee ID: ";
            cin >> empID;
        }

        void displayData() {
            cout << "Employee ID: " << empID << endl;
        }
};

class Admin : public Person {
    protected:
        string name;
        double monthlyIncome;

    public:
        void getData() {
            Person::getData();
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Monthly Income: ";
            cin >> monthlyIncome;
        }

        void displayData() {
            Person::displayData();
            cout << "Name: " << name << endl;
            cout << "Monthly Income: $" << monthlyIncome << endl;
        }

        void bonus() {
            double bonus = monthlyIncome * 0.05 * 12;
            cout << "Annual Bonus: $" << bonus << endl;
        }
};

class Accounts : public Person {
    protected:
        string name;
        double monthlyIncome;
            
    public:
        void getData() {
            Person::getData();
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Monthly Income: ";
            cin >> monthlyIncome;
        }

        void displayData() {
            Person::displayData();
            cout << "Name: " << name << endl;
            cout << "Monthly Income: $" << monthlyIncome << endl;
        }

        void bonus() {
            double bonus = monthlyIncome * 0.05 * 12;
            cout << "Annual Bonus: $" << bonus << endl;
        }
};

int main() {
    Admin adminEmp;
    Accounts accountsEmp;

    cout << "Enter Admin Employee Data:\n";
    adminEmp.getData();
    
    cout << "\nEnter Accounts Employee Data:\n";
    accountsEmp.getData();

    cout << "\nAdmin Employee Details:\n";
    adminEmp.displayData();
    adminEmp.bonus();

    cout << "\nAccounts Employee Details:\n";
    accountsEmp.displayData();
    accountsEmp.bonus();

    return 0;
}
