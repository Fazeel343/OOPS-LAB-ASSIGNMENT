#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    float kg, pounds;
    cout << "Enter Weight in Kilograms: ";
    cin >> kg;
    pounds = kg * 2.2;
    cout << fixed << setprecision(2);
    cout << "Weight in Kilograms: " << kg << " kg" << endl;
    cout << "Weight in Pounds: " << pounds << " lbs" << endl;
    return 0;
}
