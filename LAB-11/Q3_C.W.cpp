#include <iostream>
#include <stdexcept>
using namespace std;

class ArrayIndexOutOfBounds : public exception {
    public:
        const char* what() const noexcept override {
            return "Array Index out of Bounds!";
        }
};

template <typename T>
class SafeArray {
    T* arr;
    int size;
    public:
        SafeArray(int s) : size(s) {
            arr = new T[s];
        }

        ~SafeArray() {
            delete[] arr;
        }

        T& operator[](int index) {
            if (index < 0 || index >= size) throw ArrayIndexOutOfBounds();
            return arr[index];
        }
};

int main() {
    SafeArray<int> arr(5);
    try {
        arr[0] = 10;
        cout << "Value at 0: " << arr[0] << endl;
        cout << "Accessing Invalid Index..." << endl;
        cout << arr[10]; 
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
    return 0;
}
