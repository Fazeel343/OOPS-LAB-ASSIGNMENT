#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
    int id;
    string name;
};

int main() {
    int numPersons;
    cout << "Enter number of persons: ";
    cin >> numPersons;
    vector<Person> persons(numPersons);
    for (auto& p : persons) {
        cout << "Enter ID and Name: ";
        cin >> p.id >> p.name;
    }
    sort(persons.begin(), persons.end(), [](const Person& a, const Person& b) {
        return a.id < b.id;
    });
    cout << "Sorted by ID:\n";
    for (const auto& p : persons) cout << p.id << " " << p.name << endl;
    sort(persons.begin(), persons.end(), [](const Person& a, const Person& b) {
        return a.name < b.name;
    });
    cout << "Sorted by Name:\n";
    for (const auto& p : persons) cout << p.id << " " << p.name << endl;
    return 0;
}
