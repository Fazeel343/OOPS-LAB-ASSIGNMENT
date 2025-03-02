#include <iostream>
using namespace std;

class Student {
    private:
        const int roll_no;  

    public:
        Student(int roll) : roll_no(roll) {}

        void showRollNo() const {
            cout << "Student Roll No:" << endl;
            cout << "24K-" << roll_no << endl;    
        }
};

int main() {
    int roll;
    cout << "Enter Student Roll Number: ";
    cin >> roll;
    Student student(roll);
    student.showRollNo();
    return 0;
}
