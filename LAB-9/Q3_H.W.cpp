#include <iostream>
using namespace std;

class Person {
public:
    virtual void getdata() = 0;
    virtual void display() = 0;
    virtual void bonus() = 0;
};

class Admin : virtual public Person {
protected:
    string adminName;
public:
    void getdata() override {
        cout << "Enter Admin Name: ";
        cin >> adminName;
    }
    void display() override {
        cout << "Admin: " << adminName << endl;
    }
    void bonus() override {
        cout << "Admin Bonus: 5000\n";
    }
};

class Account : virtual public Person {
protected:
    string accName;
public:
    void getdata() override {
        cout << "Enter Account Name: ";
        cin >> accName;
    }
    void display() override {
        cout << "Accountant: " << accName << endl;
    }
    void bonus() override {
        cout << "Account Bonus: 3000\n";
    }
};

class Master : public Admin, public Account {
public:
    void getdata() override {
        Admin::getdata();
        Account::getdata();
    }
    void display() override {
        Admin::display();
        Account::display();
    }
    void bonus() override {
        Admin::bonus();
        Account::bonus();
        cout << "Master Bonus: 8000\n";
    }
};

int main() {
    Person* ptr;
    Master m;
    ptr = &m;
    ptr->getdata();
    ptr->display();
    ptr->bonus();

    return 0;
}
