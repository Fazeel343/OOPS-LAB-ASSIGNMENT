#include <iostream>
using namespace std;

class Shape {
private:
    double area;
public:
    Shape(double a = 0) : area(a) {}

    Shape operator+(const Shape& s) {
        return Shape(this->area + s.area);
    }

    void getData() {
        cout << "Enter area of shape: ";
        cin >> area;
    }

    void display() {
        cout << "Area: " << area << endl;
    }
};

int main() {
    Shape shape1, shape2;

    cout << "Enter details for Shape 1:\n";
    shape1.getData();
    
    cout << "Enter details for Shape 2:\n";
    shape2.getData();

    Shape totalArea = shape1 + shape2; 

    cout << "\nShape 1 ";
    shape1.display();
    cout << "Shape 2 ";
    shape2.display();
    cout << "Total Area ";
    totalArea.display();

    return 0;
}
