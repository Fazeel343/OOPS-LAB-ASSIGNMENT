#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Employee {
    int id;
    string name;
    string designation;
    int years;
};

void writeData(const string& filename, const vector<Employee>& list) {
    ofstream file(filename);
    if (!file) {
        cerr << "Unable to open File for Writing.\n";
        return;
    }
    for (auto& e : list) {
        file << e.id << " " << e.name << " " << e.designation << " " << e.years << endl;
    }
    file.close();
}

vector<Employee> readData(const string& filename) {
    vector<Employee> list;
    ifstream file(filename);
    if (!file) {
        cerr << "Unable to open File for Reading.\n";
        return list;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Employee e;
        ss >> e.id >> e.name >> e.designation >> e.years;
        if (!ss.fail()) list.push_back(e);
    }
    file.close();
    return list;
}

int main() {
    string filename = "employees.txt";

    vector<Employee> initial = {
        {1, "Ali", "developer", 1},
        {2, "Sara", "manager", 2},
        {3, "John", "tester", 3},
        {4, "Zara", "manager", 2}
    };
    writeData(filename, initial);
    cout << "Initial Data Written to File.\n";

    vector<Employee> data = readData(filename);
    vector<Employee> filtered;
    for (auto& e : data) {
        if (e.designation == "manager" && e.years >= 2)
            filtered.push_back(e);
    }

    for (auto& e : filtered) {
        e.id += 100;
        e.years += 1;
    }
    writeData(filename, filtered);
    cout << "Filtered, Modified Data Written back to File.\n";

    return 0;
}
