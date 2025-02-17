#include <iostream>
#include <string>
using namespace std;


class Invoice {
    private:
        string partNumber;       
        string partDescription;  
        int quantity;            
        double pricePerItem;     

    public:
        Invoice(string partNum, string partDesc, int qty, double price) {
            partNumber = partNum;
            partDescription = partDesc;
            quantity = (qty > 0) ? qty : 0;
            pricePerItem = (price > 0) ? price : 0.0;
        }

        double getInvoiceAmount() {
            return quantity * pricePerItem;
        }

        void displayInvoice() {
            cout << "Part Number: " << partNumber << endl;
            cout << "Part Description: " << partDescription << endl;
            cout << "Quantity: " << quantity << endl;
            cout << "Price Per Item: $" << pricePerItem << endl;
            cout << "Invoice Amount: $" << getInvoiceAmount() << endl;
        }
};

int main() {
    string partNum, partDesc;
    int qty;
    double price;

    cout << "Enter Part Number: ";
    cin >> partNum;
    cout << "Enter Part Description: ";
    cin.ignore(); 
    getline(cin, partDesc);
    cout << "Enter Quantity: ";
    cin >> qty;
    cout << "Enter Price Per Item: ";
    cin >> price;

    Invoice myInvoice(partNum, partDesc, qty, price);
    myInvoice.displayInvoice();

    return 0;
}
