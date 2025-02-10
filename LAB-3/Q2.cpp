#include <iostream>
using namespace std;

class Date {
    private:
        int month, day, year;
    public:
        Date(int m, int d, int y) {
            month = m;
            day = d;
            year = y;
        }
        void displayDate() {
            cout << month << "/" << day << "/" << year << endl;
        }
};

int main(int argc, char* argv[]) {
    Date date(2, 11, 2025); 
    date.displayDate();
    return 0;
}
