#include <iostream>
#include <string>
using namespace std;

class Employee {
    private:
        string firstName, lastName;
        double monthlySalary;
    public:
        Employee(string first, string last, double salary) {
            firstName = first;
            lastName = last;
            monthlySalary = salary > 0 ? salary : 0.0;
        }

        double getYearlySalary() {
            return monthlySalary * 12;
        }

        void giveRaise(double percentage) {
            monthlySalary += monthlySalary * (percentage / 100);
        }

        void displayInfo() {
            cout << "Employee: " << firstName << " " << lastName << " - Yearly Salary: $" << getYearlySalary() << endl;
        }
};

int main(int argc, char* argv[]) {
    Employee emp1("Adam", "Gikk", 5000);
    Employee emp2("Luis", "Smith", 6000);

    emp1.displayInfo();
    emp2.displayInfo();

    emp1.giveRaise(10);
    emp2.giveRaise(10);

    cout << "After 10% Raise:" << endl;
    
    emp1.displayInfo();
    emp2.displayInfo();

    return 0;
}
