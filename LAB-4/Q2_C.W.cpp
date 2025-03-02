#include <iostream>
#include <cmath>
using namespace std;

class Polynomial {
    private:
        double* coefficients; 
        int degree;          
    public:
        Polynomial() : degree(0) {
            coefficients = new double[1]{0}; 
        }

        Polynomial(int deg, const double* coeffs) : degree(deg) {
            coefficients = new double[degree + 1];
            for (int i = 0; i <= degree; ++i) {
                coefficients[i] = coeffs[i];
            }
        }

        Polynomial(const Polynomial& other) : degree(other.degree) {
            coefficients = new double[degree + 1];
            for (int i = 0; i <= degree; ++i) {
                coefficients[i] = other.coefficients[i];
            }
        }

        Polynomial(Polynomial&& other) noexcept : coefficients(other.coefficients), degree(other.degree) {
            other.coefficients = nullptr; 
            other.degree = 0;
        }

        ~Polynomial() {
            delete[] coefficients; 
        }

        int getDegree() const {
            return degree;
        }

        double evaluate(double x) const {
            double result = 0;
            for (int i = 0; i <= degree; ++i) {
                result += coefficients[i] * pow(x, i);
            }
            return result;
        }

        Polynomial add(const Polynomial& other) const {
            int newDegree = max(degree, other.degree);
            double* newCoeffs = new double[newDegree + 1]{0};
            for (int i = 0; i <= degree; ++i) {
                newCoeffs[i] += coefficients[i];
            }
            for (int i = 0; i <= other.degree; ++i) {
                newCoeffs[i] += other.coefficients[i];
            }
            return Polynomial(newDegree, newCoeffs);
        }

        Polynomial multiply(const Polynomial& other) const {
            int newDegree = degree + other.degree;
            double* newCoeffs = new double[newDegree + 1]{0};
            for (int i = 0; i <= degree; ++i) {
                for (int j = 0; j <= other.degree; ++j) {
                    newCoeffs[i + j] += coefficients[i] * other.coefficients[j];
                }
            }
            return Polynomial(newDegree, newCoeffs);
        }
};

int main() {
    int degree1;
    cout << "Enter the Degree of the First Polynomial: ";
    cin >> degree1;
    double* coeffs1 = new double[degree1 + 1];
    cout << "Enter Coefficients for the First Polynomial: ";
    for (int i = 0; i <= degree1; ++i) {
        cin >> coeffs1[i];
    }
    Polynomial p1(degree1, coeffs1);

    int degree2;
    cout << "Enter the Degree of the Second Polynomial: ";
    cin >> degree2;
    double* coeffs2 = new double[degree2 + 1];
    cout << "Enter Coefficients for the Second Polynomial: ";
    for (int i = 0; i <= degree2; ++i) {
        cin >> coeffs2[i];
    }
    Polynomial p2(degree2, coeffs2);


    Polynomial sum = p1.add(p2);
    Polynomial product = p1.multiply(p2);

    cout << "Degree of p1: " << p1.getDegree() << endl;
    cout << "p1 evaluated at x=2: " << p1.evaluate(2) << endl;

    return 0;
}
