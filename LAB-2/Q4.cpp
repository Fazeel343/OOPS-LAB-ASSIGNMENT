#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int employee_id;
    string name;
    float salary;  
};

struct Organization {
    string organisation_name;
    string organisation_number;
    Employee emp;
};

int main() {
    Organization org = {"NU-FAST", "NUFAST123ABC", {127, "Linus Sibastian", 400000}};
    cout << "Organisation Name: " << org.organisation_name << endl;
    cout << "Organisation Number: " << org.organisation_number << endl;
    cout << "Employee ID: " << org.emp.employee_id << endl;
    cout << "Employee Name: " << org.emp.name << endl;
    cout << "Employee Salary: " << org.emp.salary << endl;    
    return 0;
}
