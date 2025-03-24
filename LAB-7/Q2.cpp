#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double pi = 3.14159;

class Shape {
    protected:
        string color;

    public:
        Shape(string c) : color(c) {}

        virtual void draw() = 0;  
        virtual double calculateArea() = 0;
        virtual double calculatePerimeter() = 0;
};

class Circle : public Shape {
    private:
        double radius;

    public:
        Circle(string c, double r) : Shape(c), radius(r) {}

        void draw() override {
            cout << "Drawing a " << color << " Circle with Radius " << radius << endl;
        }

        double calculateArea() override {
            return pi * radius * radius;
        }

        double calculatePerimeter() override {
            return 2 * pi * radius;
        }
};

class Rectangle : public Shape {
    private:
        double width, height;

    public:
        Rectangle(string c, double w, double h) : Shape(c), width(w), height(h) {}

        void draw() override {
            cout << "Drawing a " << color << " Rectangle with Width " << width << " and Height " << height << endl;
        }

        double calculateArea() override {
            return width * height;
        }

        double calculatePerimeter() override {
            return 2 * (width + height);
        }
};

class Triangle : public Shape {
    private:
        double side1, side2, side3;

    public:
        Triangle(string c, double s1, double s2, double s3) : Shape(c), side1(s1), side2(s2), side3(s3) {}

        void draw() override {
            cout << "Drawing a " << color << " Triangle with Sides " << side1 << ", " << side2 << ", " << side3 << endl;
        }

        double calculateArea() override {
            double s = (side1 + side2 + side3) / 2;
            return sqrt(s * (s - side1) * (s - side2) * (s - side3)); 
        }

        double calculatePerimeter() override {
            return side1 + side2 + side3;
        }
};

void displayShapeDetails(Shape* shape) {
    shape->draw();
    cout << "Area: " << shape->calculateArea() << ", Perimeter: " << shape->calculatePerimeter() << "\n\n";
}

int main() {

    vector<Shape*> shapes;
    shapes.push_back(new Circle("Red", 8));
    shapes.push_back(new Rectangle("Green", 9, 12));
    shapes.push_back(new Triangle("Blue", 5, 9, 3));

    for (Shape* shape : shapes) {
        displayShapeDetails(shape);
    }
    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
