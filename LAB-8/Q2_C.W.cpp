#include <iostream>
#include <vector>
using namespace std;

class Polynomial; 

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x);
    static Polynomial derivative(const Polynomial& p);
};

class Polynomial {
private:
    vector<int> coefficients;

public:
    Polynomial() {
        int degree;
        cout << "Enter the degree of the polynomial: ";
        cin >> degree;

        coefficients.resize(degree + 1);
        cout << "Enter " << degree + 1 << " coefficients (from lowest to highest degree): ";
        for (int i = 0; i <= degree; i++) {
            cin >> coefficients[i];
        }
        trim();
    }

    Polynomial operator+(const Polynomial& p) const {
        size_t maxSize = max(coefficients.size(), p.coefficients.size());
        vector<int> result(maxSize, 0);

        for (size_t i = 0; i < coefficients.size(); i++)
            result[i] += coefficients[i];

        for (size_t i = 0; i < p.coefficients.size(); i++)
            result[i] += p.coefficients[i];

        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& p) const {
        size_t maxSize = max(coefficients.size(), p.coefficients.size());
        vector<int> result(maxSize, 0);

        for (size_t i = 0; i < coefficients.size(); i++)
            result[i] += coefficients[i];

        for (size_t i = 0; i < p.coefficients.size(); i++)
            result[i] -= p.coefficients[i];

        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& p) const {
        size_t newSize = coefficients.size() + p.coefficients.size() - 1;
        vector<int> result(newSize, 0);

        for (size_t i = 0; i < coefficients.size(); i++) {
            for (size_t j = 0; j < p.coefficients.size(); j++) {
                result[i + j] += coefficients[i] * p.coefficients[j];
            }
        }

        return Polynomial(result);
    }

    friend class PolynomialUtils;

    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        bool first = true;
        for (int i = p.coefficients.size() - 1; i >= 0; i--) {
            if (p.coefficients[i] != 0) {
                if (!first) os << (p.coefficients[i] > 0 ? " + " : " - ");
                else if (p.coefficients[i] < 0) os << "-";

                os << abs(p.coefficients[i]);
                if (i > 0) os << "x^" << i;

                first = false;
            }
        }
        if (first) os << "0";  
        return os;
    }

private:
    Polynomial(const vector<int>& coeffs) : coefficients(coeffs) {
        trim();
    }

    void trim() {
        while (!coefficients.empty() && coefficients.back() == 0) {
            coefficients.pop_back();
        }
    }
};

int PolynomialUtils::evaluate(const Polynomial& p, int x) {
    int result = 0;
    int power = 1;
    for (int coeff : p.coefficients) {
        result += coeff * power;
        power *= x;
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial& p) {
    if (p.coefficients.size() <= 1) return Polynomial({0});

    vector<int> derivativeCoeffs(p.coefficients.size() - 1);
    for (size_t i = 1; i < p.coefficients.size(); i++) {
        derivativeCoeffs[i - 1] = i * p.coefficients[i];
    }
    return Polynomial(derivativeCoeffs);
}

int main() {
    cout << "Enter first polynomial:\n";
    Polynomial p1;

    cout << "Enter second polynomial:\n";
    Polynomial p2;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Evaluate Polynomial\n";
        cout << "5. Derivative\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Sum: " << (p1 + p2) << endl;
                break;
            case 2:
                cout << "Difference: " << (p1 - p2) << endl;
                break;
            case 3:
                cout << "Product: " << (p1 * p2) << endl;
                break;
            case 4: {
                int x;
                cout << "Enter value of x: ";
                cin >> x;
                cout << "p1(" << x << ") = " << PolynomialUtils::evaluate(p1, x) << endl;
                cout << "p2(" << x << ") = " << PolynomialUtils::evaluate(p2, x) << endl;
                break;
            }
            case 5:
                cout << "Derivative of p1: " << PolynomialUtils::derivative(p1) << endl;
                cout << "Derivative of p2: " << PolynomialUtils::derivative(p2) << endl;
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
