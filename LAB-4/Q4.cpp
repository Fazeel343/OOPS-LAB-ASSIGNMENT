#include <iostream>
#include <string>
using namespace std;


class Book {
    private:
        string title;         
        string author;        
        double price;         
        string publisher;     
        int stock;          

    public:
        Book(string t, string a, double p, string pub, int s) {
            title = t;
            author = a;
            price = p;
            publisher = pub;
            stock = s;
        }

        string getTitle() {
            return title;
        }

        string getAuthor() {
            return author;
        }

        double getPrice() {
            return price;
        }

        string getPublisher() {
            return publisher;
        }

        int getStock() {
            return stock;
        }

        void updateStock(int quantitySold) {
            stock -= quantitySold;
        }

        void displayBookDetails() {
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Price: $" << price << endl;
            cout << "Stock: " << stock << " copies" << endl;
        }

        bool checkAvailability(int requiredCopies) {
            if (stock >= requiredCopies) {
                updateStock(requiredCopies); 
                return true;
            }
            return false;
        }
};

Book* searchBook(Book inventory[], int inventorySize, string title, string author) {
    for (int i = 0; i < inventorySize; i++) {
        if (inventory[i].getTitle() == title && inventory[i].getAuthor() == author) {
            return &inventory[i]; 
        }
    }
    return nullptr; 
}

int main() {
    Book inventory[] = {
        Book("The Great Gatsby", "F. Scott Fitzgerald", 9.99, "Little, Brown and Company", 7),
        Book("Moby-Dick", "Herman Melville", 14.99, "Secker & Warburg", 4),
        Book("The Hobbit", "J.R.R. Tolkien", 7.99, "J.B. Lippincott & Co.", 3)
    };

    int inventorySize = sizeof(inventory) / sizeof(inventory[0]); 
    string title, author;
    int requiredCopies;

    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter author name: ";
    getline(cin, author);
    Book* book = searchBook(inventory, inventorySize, title, author);

    if (book == nullptr) {
        cout << "Sorry, the Book is not Available in our Inventory.\n";
    } else {
        cout << "Book found!\n";
        book->displayBookDetails();
        cout << "Enter the Number of Copies Required: ";
        cin >> requiredCopies;
        if (book->checkAvailability(requiredCopies)) {
            double totalCost = requiredCopies * book->getPrice();
            cout << "Total Cost for " << requiredCopies << " Copies: $" << totalCost << endl;
        } else {
            cout << "Required Copies not in Stock.\n";
        }
    }

    return 0;
}
