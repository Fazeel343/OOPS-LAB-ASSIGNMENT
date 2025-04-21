#include <iostream>
using namespace std;

class Shape {
public:
    virtual double getArea() = 0;
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double getArea() override {
        return length * width;
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double getArea() override {
        return 0.5 * base * height;
    }
};

int main() {
    Rectangle r(10, 5);
    Triangle t(8, 6);

    cout << "Rectangle Area: " << r.getArea() << endl;
    cout << "Triangle Area: " << t.getArea() << endl;

    return 0;
}
