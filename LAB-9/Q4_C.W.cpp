#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Flight {
private:
    string flightNumber, departure, arrival;
    int capacity;
    vector<string> bookedPassengers;

    bool isAlreadyBooked(const string& passengerID) {
        for (const string& id : bookedPassengers) {
            if (id == passengerID) return true;
        }
        return false;
    }

public:
    Flight(string fn, string dep, string arr, int cap) :
        flightNumber(fn), departure(dep), arrival(arr), capacity(cap) {}

    bool bookSeat(const string& passengerID) {
        if (bookedPassengers.size() >= capacity) return false;
        if (isAlreadyBooked(passengerID)) return false;

        bookedPassengers.push_back(passengerID);
        return true;
    }

    bool cancelSeat(const string& passengerID) {
        for (auto it = bookedPassengers.begin(); it != bookedPassengers.end(); ++it) {
            if (*it == passengerID) {
                bookedPassengers.erase(it);
                return true;
            }
        }
        return false;
    }

    void printFlightDetails() const {
        cout << flightNumber << " | " << departure << " -> " << arrival
             << " | Seats booked: " << bookedPassengers.size() << "/" << capacity << endl;
    }
};

class Passenger {
private:
    string id, name;

public:
    Passenger(string i, string n) : id(i), name(n) {}

    void requestBooking(Flight& flight) {
        if (flight.bookSeat(id)) cout << name << " successfully booked.\n";
        else cout << name << " booking failed.\n";
    }

    void requestCancellation(Flight& flight) {
        if (flight.cancelSeat(id)) cout << name << " cancelled successfully.\n";
        else cout << name << " cancellation failed.\n";
    }
};

int main() {
    Flight f1("PK303", "Lahore", "Karachi", 2);
    Passenger p1("001", "Ayesha");
    Passenger p2("002", "Ali");
    Passenger p3("003", "Sara");

    p1.requestBooking(f1);
    p2.requestBooking(f1);
    p3.requestBooking(f1); // should fail due to capacity

    f1.printFlightDetails();

    p1.requestCancellation(f1);
    f1.printFlightDetails();

    return 0;
}
