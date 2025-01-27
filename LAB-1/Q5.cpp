#include <iostream>
using namespace std;
int main() {
    string movieName;
    int adultTickets, childTickets;
    float adultPrice, childPrice, donationPercent, grossAmount, donation, netSale;
    cout << "Enter Movie Name: ";
    getline(cin, movieName);
    cout << "Enter Adult Ticket Price: ";
    cin >> adultPrice;
    cout << "Enter Child Ticket Price: ";
    cin >> childPrice;
    cout << "Enter Number of Adult Tickets Sold: ";
    cin >> adultTickets;
    cout << "Enter Number of Child Tickets Sold: ";
    cin >> childTickets;
    cout << "Enter Percentage of Gross Amount Donated: ";
    cin >> donationPercent;
    grossAmount = (adultTickets * adultPrice) + (childTickets * childPrice);
    donation = grossAmount * (donationPercent / 100);
    netSale = grossAmount - donation;
    cout << "Movie Name: " << movieName << endl;
    cout << "Number of Tickets Sold: " << (adultTickets + childTickets) << endl;
    cout << "Gross Amount: $" << grossAmount << endl;
    cout << "Percentage of Gross Amount Donated: " << donationPercent << "%" << endl;
    cout << "Amount Donated: $" << donation << endl;
    cout << "Net Sale: $" << netSale << endl;
    return 0;
}
