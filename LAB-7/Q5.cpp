#include <iostream>
#include <vector>
using namespace std;

class Media {
    protected:
        string title;
        string publicationDate;
        int uniqueID;
        string publisher;
    public:
        Media(string t, string date, int id, string pub) : title(t), publicationDate(date), uniqueID(id), publisher(pub) {}
        virtual void displayInfo() {
            cout << "Title: " << title << ", Published: " << publicationDate << ", ID: " << uniqueID << ", Publisher: " << publisher << endl;
        }
        string getTitle() { 
            return title; 
        }
        string getPublicationDate() { 
            return publicationDate; 
        }
};

class Book : public Media {
    private:
        string author;
        string ISBN;
        int numberOfPages;
    public:
        Book(string t, string date, int id, string pub, string auth, string isbn, int pages)
            : Media(t, date, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}
        void displayInfo() override {
            Media::displayInfo();
            cout << "Author: " << author << ", ISBN: " << ISBN << ", Pages: " << numberOfPages << endl;
        }
        string getAuthor() { 
            return author; 
        }
};

class DVD : public Media {
    private:
        string director;
        int duration;
        string rating;
    public:
        DVD(string t, string date, int id, string pub, string dir, int dur, string rate)
            : Media(t, date, id, pub), director(dir), duration(dur), rating(rate) {}
        void displayInfo() override {
            Media::displayInfo();
            cout << "Director: " << director << ", Duration: " << duration << " mins, Rating: " << rating << endl;
        }
};

class CD : public Media {
    private:
        string artist;
        int numberOfTracks;
        string genre;
    public:
        CD(string t, string date, int id, string pub, string art, int tracks, string gen)
            : Media(t, date, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}
        void displayInfo() override {
            Media::displayInfo();
            cout << "Artist: " << artist << ", Tracks: " << numberOfTracks << ", Genre: " << genre << endl;
        }
};

class Magazine : public Media {
    private:
        int issueNumber;
        string category;
    public:
        Magazine(string t, string date, int id, string pub, int issue, string cat)
            : Media(t, date, id, pub), issueNumber(issue), category(cat) {}

        void displayInfo() override {
            Media::displayInfo();
            cout << "Issue Number: " << issueNumber << ", Category: " << category << endl;
        }
};

class Library {
    private:
        vector<Media *> catalog;
    public:
        void addMedia(Media *m) {
            catalog.push_back(m);
        }
        void displayAllMedia() {
            for (Media *m : catalog) {
                m->displayInfo();
                cout << "-----------------------------" << endl;
            }
        }
        void searchByTitle(string title) {
            for (Media *m : catalog) {
                if (m->getTitle() == title) {
                    cout << "Media Found:\n";
                    m->displayInfo();
                    return;
                }
            }
            cout << "No Media Found with the Title: " << title << endl;
        }
        void searchByPublicationDate(string date) {
            for (Media *m : catalog) {
                if (m->getPublicationDate() == date) {
                    cout << "Media Found:\n";
                    m->displayInfo();
                    return;
                }
            }
            cout << "No media found published in: " << date << endl;
        }

        void searchByAuthor(string author) {
            for (Media *m : catalog) {
                Book *b = dynamic_cast<Book *>(m);
                if (b && b->getAuthor() == author) {
                    cout << "Book Found:\n";
                    b->displayInfo();
                    return;
                }
            }
            cout << "No books found by author: " << author << endl;
        }
};

int main() {
    Library library;

    library.addMedia(new Book("The Great Gatsby", "1925", 101, "Scribner", "F. Scott Fitzgerald", "123456789", 180));
    library.addMedia(new DVD("Inception", "2010", 102, "Warner Bros", "Christopher Nolan", 148, "PG-13"));
    library.addMedia(new CD("Thriller", "1982", 103, "Epic Records", "Michael Jackson", 9, "Pop"));
    library.addMedia(new Magazine("National Geographic", "2024", 104, "NatGeo", 500, "Science"));

    cout << "Library Catalog:\n";
    library.displayAllMedia();

    cout << "\nSearching for 'Inception':\n";
    library.searchByTitle("Inception");

    cout << "\nSearching for books by 'F. Scott Fitzgerald':\n";
    library.searchByAuthor("F. Scott Fitzgerald");

    return 0;
}
