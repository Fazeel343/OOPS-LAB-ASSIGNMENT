#include <iostream>
using namespace std;

class DynamicArray {
    private:
        int* array; 
        int size;   
    public:
        DynamicArray() : array(nullptr), size(0) {}

        DynamicArray(int n) : size(n) {
            array = new int[size](); 
        }

        DynamicArray(const DynamicArray& other) : size(other.size) {
            array = new int[size];
            for (int i = 0; i < size; ++i) {
                array[i] = other.array[i]; 
            }
        }

        DynamicArray(DynamicArray&& other) noexcept : array(other.array), size(other.size) {
            other.array = nullptr; 
            other.size = 0;
        }

        DynamicArray& operator=(const DynamicArray& other) {
            if (this != &other) { 
                delete[] array; 
                size = other.size;
                array = new int[size];
                for (int i = 0; i < size; ++i) {
                    array[i] = other.array[i];
                }
            }
            return *this;
        }

        DynamicArray& operator=(DynamicArray&& other) noexcept {
            if (this != &other) { 
                delete[] array; 
                array = other.array; 
                size = other.size;
                other.array = nullptr; 
                other.size = 0;
            }
            return *this;
        }

        ~DynamicArray() {
            delete[] array; 
        }

        int getSize() const {
            return size;
        }

        int& at(int index) {
            return array[index];
        }

        const int& at(int index) const {
            return array[index];
        }

        void resize(int newSize) {
            int* newArray = new int[newSize](); 
            for (int i = 0; i < min(size, newSize); ++i) {
                newArray[i] = array[i]; 
            }
            delete[] array; 
            array = newArray; 
            size = newSize; 
        }
};

int main() {
    int size;
    cout << "Enter the Size of the Dynamic Array: ";
    cin >> size;
    DynamicArray arr(size); 
    for (int i = 0; i < arr.getSize(); ++i) {
        cout << "Enter Element " << i << ": ";
        int value;
        cin >> value;
        arr.at(i) = value; 

    }

    cout << "Dynamic Array Elements: ";
    for (int i = 0; i < arr.getSize(); ++i) {
        cout << arr.at(i) << " "; 
    }
    cout << endl;
    arr.resize(10); 
    cout << "Resized Dynamic Array Elements: ";
    for (int i = 0; i < arr.getSize(); ++i) {
        cout << arr.at(i) << " "; 
    }
    cout << endl;
    return 0;
}
