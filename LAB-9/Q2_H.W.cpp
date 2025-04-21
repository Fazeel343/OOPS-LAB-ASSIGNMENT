#include <iostream>
using namespace std;

class Car {
protected:
    string model;
    double price;

public:
    Car(string m) : model(m), price(0) {}
    virtual void setPrice(double p) = 0;
    virtual void display() const {
        cout << "Model: " << model << ", Price: " << price << endl;
    }
};

class Color : public Car {
private:
    string color;
public:
    Color(string m, string c) : Car(m), color(c) {}
    void setPrice(double p) override {
        price = p + 500; // color premium
    }
    void display() const override {
        cout << "Color Model: " << model << ", Color: " << color << ", Price: " << price << endl;
    }
};

class Company : public Car {
private:
    string companyName;
public:
    Company(string m, string c) : Car(m), companyName(c) {}
    void setPrice(double p) override {
        price = p + 1000; // brand value
    }
    void display() const override {
        cout << "Company Model: " << model << ", Company: " << companyName << ", Price: " << price << endl;
    }
};

int main() {
    Color c("Corolla", "Red");
    c.setPrice(20000);
    c.display();

    Company cmp("Civic", "Honda");
    cmp.setPrice(25000);
    cmp.display();

    return 0;
}
