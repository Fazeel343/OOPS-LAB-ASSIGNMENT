#include <iostream>
using namespace std;
int main() {
    string studentName;
    float scores[5], total = 0, average;
    cout << "Enter Student Name: ";
    getline(cin, studentName);
    cout << "Enter 5 test scores: ";
    for (int i = 0; i < 5; i++) {
        cin >> scores[i];
        total += scores[i];
    }
    average = total / 5;
    cout << endl << "Student Name: " << studentName << endl;
    cout << "Test scores: ";
    for (int i = 0; i < 5; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;
    cout << "Average test score: " << average << endl;
    return 0;
}
