#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "Stack underflow! Cannot access top/pop on empty stack.";
    }
};

template <typename T>
class Stack {
    vector<T> data;
public:
    void push(T val) {
        data.push_back(val);
    }

    void pop() {
        if (data.empty()) throw StackUnderflowException();
        data.pop_back();
    }

    T top() {
        if (data.empty()) throw StackUnderflowException();
        return data.back();
    }

    bool isEmpty() const {
        return data.empty();
    }
};

int main() {
    Stack<int> s;
    try {
        s.push(10);
        s.push(20);
        cout << "Top: " << s.top() << endl;
        s.pop();
        s.pop();
        s.pop();  
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
    return 0;
}
