#include <iostream>
using namespace std;
int main() {
    int customerID, unitsConsumed;
    string customerName;
    cout << "Enter Customer ID: ";
    cin >> customerID;
    cout << "Enter Customer Name: ";
    cin >> customerName;
    cout << "Enter Units Consumed: ";
    cin >> unitsConsumed;
    float rate, amount, surcharge = 0, netAmount;

    if (unitsConsumed <= 199) {
        rate = 16.20;
    } else if (unitsConsumed < 300) {
        rate = 20.10;
    } else if (unitsConsumed < 500) {
        rate = 27.10;
    } else {
        rate = 35.90;
    }
    amount = unitsConsumed * rate;
    if (amount > 18000) {
        surcharge = amount * 0.15;
    }
    netAmount = amount + surcharge;
    cout << "\nCustomer ID: " << customerID;
    cout << "\nCustomer Name: " << customerName;
    cout << "\nUnits Consumed: " << unitsConsumed;
    cout << "\nAmount Charges @Rs. " << rate << " per unit: " << amount;
    if (surcharge > 0) {
        cout << "\nSurcharge Amount: " << surcharge;
    }
    cout << "\nNet Amount Paid by the Customer: " << netAmount << endl;
    return 0;
}
