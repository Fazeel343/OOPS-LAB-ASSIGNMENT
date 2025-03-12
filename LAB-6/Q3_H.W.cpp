#include <iostream>
using namespace std;

class Student {
    protected:
        string name;
        int rollNumber;
    public:
        void inputStudentDetails() {
            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Roll Number: ";
            cin >> rollNumber;
        }
        void displayStudentDetails() {
            cout << "\nStudent Name: " << name << "\nRoll Number: " << rollNumber << endl;
        }
};

class Marks : public Student {
    protected:
        int numSubjects;
        double* marks;
    public:
        Marks(int subjects) : numSubjects(subjects) {
            marks = new double[numSubjects];
        }
        void inputMarks() {
            cout << "Enter marks for " << numSubjects << " subjects:\n";
            for (int i = 0; i < numSubjects; i++) {
                cout << "Subject " << i + 1 << ": ";
                cin >> marks[i];
            }
        }
        void displayMarks() {
            cout << "\nMarks Obtained:\n";
            for (int i = 0; i < numSubjects; i++) {
                cout << "Subject " << i + 1 << ": " << marks[i] << endl;
            }
        }
        double getTotalMarks() {
            double total = 0;
            for (int i = 0; i < numSubjects; i++) {
                total += marks[i];
            }
            return total;
        }
        ~Marks() {
            delete[] marks;
        }
};

class Result : public Marks {
    public:
        Result(int subjects) : Marks(subjects) {}
        void displayResult() {
            displayStudentDetails();
            displayMarks();
            double total = getTotalMarks();
            double average = total / numSubjects;
            cout << "\nTotal Marks: " << total << endl;
            cout << "Average Marks: " << average << endl;
        }
};

int main() {
    int numSubjects;
    cout << "Enter number of subjects: ";
    cin >> numSubjects;
    Result student(numSubjects);
    student.inputStudentDetails();
    student.inputMarks();
    student.displayResult();
    return 0;
}
