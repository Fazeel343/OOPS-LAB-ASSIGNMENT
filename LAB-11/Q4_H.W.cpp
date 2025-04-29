#include <iostream>
using namespace std;

template <typename T>
class Base {
    protected:
        T a, b;
    public:
        Base(T x, T y) : a(x), b(y) {}
        void showProduct() {
            cout << "Base Product: " << a * b << endl;
        }
};

template <typename T>
class Derived : public Base<T> {
    T c, d;
    public:
        Derived(T x, T y, T z, T w) : Base<T>(x, y), c(z), d(w) {}
        void showAllProducts() {
            this->showProduct();
            cout << "Derived Product: " << c * d << endl;
        }
};

int main() {
    Derived<int> obj(2, 3, 4, 5);
    obj.showAllProducts();
    return 0;
}
