#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    Number(int v = 0) {
        value = v;
    }

    Number operator--() {
        value *= 4;
        return *this;
    }

    Number operator--(int) {
        Number temp = *this;
        value /= 4;
        return temp;
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    Number n(num);

    cout << "\nOriginal: ";
    n.display();

    cout << "\nUsing Prefix --n (Multiplication by 4): ";
    --n;
    n.display();

    cout << "\nUsing Postfix n-- (Division by 4): ";
    n--;
    n.display();

    return 0;
}
