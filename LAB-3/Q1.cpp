#include <iostream>
#include <string>
using namespace std;

class User {
    public:
        int Age;
        string Name;
};

int main(int argc, char* argv[]) {
    User user;
    user.Name = "Teo";
    user.Age = 24;
    cout << "My name is " << user.Name << " and I'm " << user.Age << " years old." << endl;
    return 0;
}
