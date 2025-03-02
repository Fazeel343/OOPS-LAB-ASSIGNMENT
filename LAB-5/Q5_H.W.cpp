#include <iostream>
using namespace std;

class Car {
    public:
        int engineHorsePower;
        int seatingCapacity;
        int noOfSpeakers;
        Car(int hP, int seats, int speakers) : engineHorsePower(hP), seatingCapacity(seats), noOfSpeakers(speakers) {}
        void showDetails() const {
            cout << "Horespower: " << engineHorsePower << endl;
            cout << "Seating: " << seatingCapacity << endl; 
            cout << "Speakers: " << noOfSpeakers << endl;
        }
};

int main() {
    int hP, seats, speakers;
    cout << "Enter Engine Horsepower: ";
    cin >> hP;
    cout << "Enter Seating Capacity: ";
    cin >> seats;
    cout << "Enter Number of Speakers: ";
    cin >> speakers;
    Car myCar(hP, seats, speakers);
    myCar.showDetails();
    return 0;
}