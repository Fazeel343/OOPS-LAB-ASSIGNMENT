#include <iostream>
#include <vector>
using namespace std;

class Car {
    public: 
        string name;
        int id;
        Car(string n, int i) : name(n), id(i) {}
};

class Garage {
    private:    
        vector<Car*> cars;
    public:
        void parkCar(Car* car) {
            cars.push_back(car);
        }
        void listCars() {
            for (Car* car : cars) {
                cout << "Car ID: " << car->id << ", Name: " << car->name << endl;
            }
        }
};

int main() {
    Car car1("Toyota", 101), car2("Hyundai", 102);
    Garage garage;
    garage.parkCar(&car1);
    garage.parkCar(&car2);
    garage.listCars();
    return 0;
}
