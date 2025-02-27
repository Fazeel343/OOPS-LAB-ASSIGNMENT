#include <iostream>
using namespace std;

class Engine {
    private:
        bool isRunning;
    public:
        Engine() {
            isRunning = false;
            cout << "Engine Constructed" << endl;
        }
        ~Engine() {
            cout << "Engine Destroyed" << endl;
        }
        void start() {
            isRunning = true;
            cout << "Engine started" << endl;
        }
        void stop() {
            isRunning = false;
            cout << "Engine stopped" << endl;
        }
};

class Car {
    private:
        Engine engine;
    public:
        Car() {
            cout << "Car Constructed" << endl;
        }
        ~Car() {
            cout << "Car Destroyed" << endl;
        }
        void startCar() {
            engine.start();
        }
        void stopCar() {
            engine.stop();
        }
};

int main() {
    cout << "Creating Car object........." << endl; 
    Car car;
    car.startCar();
    car.stopCar();
    cout << "Car object going out of scope......" << endl;
    return 0;
}