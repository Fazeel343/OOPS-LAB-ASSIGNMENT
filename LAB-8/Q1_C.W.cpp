#include <iostream>
using namespace std;

class Fraction {

    private:
        int denominator, numerator;
        int gcd(int a, int b) {
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
        void reduce() {
            int gcdValue = gcd(numerator, denominator);
            numerator /= gcdValue;
            denominator/= gcdValue;    
        }
    
    public:
        Fraction(int num = 0, int denom = 1) {
            if (denom == 0) {
                cout << "Error: Denominator cannot be Zero!" << endl;
            }
            numerator = num;
            denominator = denom;
            reduce();
        }

        void display() {
            cout << numerator << "/" << denominator;
        }

        Fraction operator+(const Fraction& f) {
            return Fraction(numerator * f.denominator + f.numerator * denominator, denominator * f.denominator); 
        }

        Fraction operator-(const Fraction& f) {
            return Fraction(numerator * f.denominator - f.numerator * denominator, denominator * f.denominator);
        }
        
        Fraction operator*(const Fraction& f) {
            return Fraction(numerator * f.numerator, denominator * f.denominator);
        }
        
        Fraction operator/(const Fraction& f) {
            if (f.numerator == 0) {
                cout << "Error: Cannot divide by zero!\n";
                return *this;
            }
            return Fraction(numerator * f.denominator, denominator * f.numerator);
        }

        bool operator==(const Fraction& f) {
            return numerator * f.denominator == denominator * f.numerator;
        }
        
        bool operator!=(const Fraction& f) {
            return !(*this == f);
        }
        
        bool operator<(const Fraction& f) {
            return numerator * f.denominator < denominator * f.numerator;
        }
        
        bool operator>(const Fraction& f) {
            return numerator * f.denominator > denominator * f.numerator;
        }
        
        bool operator<=(const Fraction& f) {
            return !(*this > f);
        }
        
        bool operator>=(const Fraction& f) {
            return !(*this < f);
        }

};
int main() {
    int num1, num2, denom1, denom2, choice;

    cout << "Enter First Fraction (numerator denominator)";
    cin >> num1 >> denom1;
    Fraction f1(num1, denom1);

    cout << "Enter Second Fraction (numerator denominator)";
    cin >> num2 >> denom2;
    Fraction f2(num2, denom2);

    do {
        cout << "\nMenu:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Compare\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: (f1 + f2).display(); break;
            case 2: (f1 - f2).display(); break;
            case 3: (f1 * f2).display(); break;
            case 4: (f1 / f2).display(); break;
            case 5:
                if (f1 == f2)
                    cout << "Both fractions are equal.\n";
                else if (f1 < f2)
                    cout << "Fraction 1 is less than Fraction 2.\n";
                else
                    cout << "Fraction 1 is greater than Fraction 2.\n";
                break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}