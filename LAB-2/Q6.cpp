#include <iostream>
#include <vector>
using namespace std;

struct Student {
    int id;
    vector<string> subjects;
};

int main() {
    int numStudents;
    cout << "Enter number of students: ";
    cin >> numStudents;
    vector<Student> students(numStudents);
    for (auto& s : students) {
        cout << "Enter Student ID: ";
        cin >> s.id;
        cout << "Enter number of subjects: ";
        int numSubs;
        cin >> numSubs;
        s.subjects.resize(numSubs);
        cout << "Enter subjects: ";
        for (auto& sub : s.subjects) cin >> sub;
    }
    cout << "Student Data:\n";
    for (const auto& s : students) {
        cout << "ID: " << s.id << " Subjects: ";
        for (const auto& sub : s.subjects) cout << sub << " ";
        cout << endl;
    }
    return 0;
}
