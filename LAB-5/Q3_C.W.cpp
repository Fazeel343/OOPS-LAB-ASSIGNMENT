#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Book {
    public:
        string title;
        string isbn;
        Book(string t, string i) : title(t), isbn(i) {}
};

class Catalog {
    private:
        vector<Book> books;
    public:
        void addBook(const Book& book) {
            books.push_back(book);
        }

        string findBook(string isbn) {
            for (const auto& book : books) {
                if (book.isbn == isbn) {
                    return "Book found: " + book.title;
                }
            }
            return "Book not found";
        }
};

class Library {
    private:
        Catalog catalog;
        vector<shared_ptr<Book>> books;
    public:
        void addBook(shared_ptr<Book> book) {
            books.push_back(book);
            catalog.addBook(*book);
        }

        void findBookInCatalog(string isbn) {
            cout << catalog.findBook(isbn) << endl;
        }
};

int main() {
    Library lib;
    shared_ptr<Book> book1 = make_shared<Book>("JAVA ", "1234");
    shared_ptr<Book> book2 = make_shared<Book>("BUSINESS ANALYTICS", "5678");
    lib.addBook(book1);
    lib.addBook(book2);
    lib.findBookInCatalog("1234");
    lib.findBookInCatalog("9392");  
    return 0;
}
