#include <iostream>
#include <string>
using namespace std;

class Currency {
    protected:
        double amount;
        string currencyCode;
        string currencySymbol;
        double exchangeRate; 

    public:
        Currency(double amt, string code, string symbol, double rate)
            : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

        virtual double convertToBase() const {
            return amount * exchangeRate; 
        }

        virtual double convertTo(const Currency &targetCurrency) const {
            double baseValue = convertToBase();
            return baseValue / targetCurrency.exchangeRate; 
        }

        virtual void displayCurrency() const {
            cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
        }
};

class Dollar : public Currency {
    public:
        Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}
        void displayCurrency() const override {
            cout << "$" << amount << " USD" << endl;
        }
};

class Euro : public Currency {
    public:
        Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {} 
        void displayCurrency() const override {
            cout << "€" << amount << " EUR" << endl;
        }
};

class Rupee : public Currency {
    public:
        Rupee(double amt) : Currency(amt, "PKR", "₨", 0.0035) {} 
        void displayCurrency() const override {
            cout << "₨" << amount << " PKR" << endl;
        }
};

int main() {
    
    Dollar usd(100);
    Euro eur(50);
    Rupee pkr(5000);

    cout << "Original Amounts:" << endl;
    usd.displayCurrency();
    eur.displayCurrency();
    pkr.displayCurrency();

    cout << "\nConversions:" << endl;
    cout << "$100 USD to EUR: " << usd.convertTo(eur) << " EUR" << endl;
    cout << "50 EUR to USD: " << eur.convertTo(usd) << " USD" << endl;
    cout << "5000 PKR to USD: " << pkr.convertTo(usd) << " USD" << endl;
    cout << "$100 USD to PKR: " << usd.convertTo(pkr) << " PKR" << endl;

    return 0;
}
