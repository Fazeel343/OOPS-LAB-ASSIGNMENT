#include <iostream>
using namespace std;

class Circle {
    private:
        double radius;
        const double PI = 3.14159265;

    public:
        Circle(double r) {
            radius = r;
        }

        double getArea() {
            return PI * radius * radius;
        }

        double getPerimeter() {
            return 2 * PI * radius;
        }
};

int main() {
    double r;
    cout << "Enter the radius of the circle: ";
    cin >> r;

    Circle c(r);

    cout << "Area: " << c.getArea() << endl;
    cout << "Perimeter: " << c.getPerimeter() << endl;

    return 0;
}
