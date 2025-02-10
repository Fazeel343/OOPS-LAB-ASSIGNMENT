#include <iostream>
#include <string>
using namespace std;

class Book {
    private:
        string bookName;
        string isbn;
        string authorName;
        string publisher;

    public:
        Book(string bookName, string isbn, string authorName, string publisher) 
            : bookName(bookName), isbn(isbn), authorName(authorName), publisher(publisher) {}

        string getBookInfo() {
            return "Book Name: " + bookName + "\nISBN: " + isbn + 
                "\nAuthor: " + authorName + "\nPublisher: " + publisher;
        }
};

int main(int argc, char* argv[]) {
    Book books[5] = {
        Book("C++ Basics", "123456789", "Author A", "Publisher X"),
        Book("Data Structures", "987654321", "Author B", "Publisher Y"),
        Book("Algorithms", "112233445", "Author C", "Publisher Z"),
        Book("Operating Systems", "998877665", "Author D", "Publisher W"),
        Book("Network Security", "334455667", "Author E", "Publisher V")
    };

    for (int i = 0; i < 5; i++) {
        cout << "Book " << i + 1 << " Details:\n" << books[i].getBookInfo() << "\n" << endl;
    }
    
    return 0;
}
