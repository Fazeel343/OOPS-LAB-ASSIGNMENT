#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BigInteger {
private:
    vector<int> digits;
    bool isNegative;

    // Helper function to remove leading zeros
    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
        if (digits.size() == 1 && digits[0] == 0)
            isNegative = false;
    }

public:
    // Constructors
    BigInteger() : isNegative(false) {}

    BigInteger(string str) {
        isNegative = (str[0] == '-');
        if (isNegative) str = str.substr(1);

        digits.clear();
        for (int i = str.length() - 1; i >= 0; i--) {
            digits.push_back(str[i] - '0');
        }
        removeLeadingZeros();
    }

    // Addition Operator
    BigInteger operator+(const BigInteger& other) const {
        if (isNegative == other.isNegative) {
            BigInteger result = add(*this, other);
            result.isNegative = isNegative;
            return result;
        }
        if (absGreaterOrEqual(*this, other)) {
            BigInteger result = subtract(*this, other);
            result.isNegative = isNegative;
            return result;
        } else {
            BigInteger result = subtract(other, *this);
            result.isNegative = other.isNegative;
            return result;
        }
    }

    // Subtraction Operator
    BigInteger operator-(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            BigInteger result = add(*this, other);
            result.isNegative = isNegative;
            return result;
        }
        if (absGreaterOrEqual(*this, other)) {
            BigInteger result = subtract(*this, other);
            result.isNegative = isNegative;
            return result;
        } else {
            BigInteger result = subtract(other, *this);
            result.isNegative = !other.isNegative;
            return result;
        }
    }

    // Multiplication Operator
    BigInteger operator*(const BigInteger& other) const {
        BigInteger result = multiply(*this, other);
        result.isNegative = (isNegative != other.isNegative);
        return result;
    }

    // Comparison Operators
    bool operator==(const BigInteger& other) const {
        if (isNegative != other.isNegative) return false;
        if (digits.size() != other.digits.size()) return false;
        for (size_t i = 0; i < digits.size(); i++) {
            if (digits[i] != other.digits[i]) return false;
        }
        return true;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (isNegative != other.isNegative) return isNegative;
        return isNegative ? absGreater(*this, other) : absLess(*this, other);
    }

    bool operator>(const BigInteger& other) const {
        return !(*this == other) && !(*this < other);
    }

    // Input Operator
    friend istream& operator>>(istream& in, BigInteger& num) {
        string str;
        in >> str;
        num = BigInteger(str);
        return in;
    }

    // Output Operator
    friend ostream& operator<<(ostream& out, const BigInteger& num) {
        if (num.isNegative) out << "-";
        for (int i = num.digits.size() - 1; i >= 0; i--) {
            out << num.digits[i];
        }
        return out;
    }

private:
    // Helper Function: Add Two Numbers
    static BigInteger add(const BigInteger& a, const BigInteger& b) {
        BigInteger result;
        int carry = 0;
        size_t maxSize = (a.digits.size() > b.digits.size()) ? a.digits.size() : b.digits.size();

        for (size_t i = 0; i < maxSize || carry; i++) {
            int sum = carry;
            if (i < a.digits.size()) sum += a.digits[i];
            if (i < b.digits.size()) sum += b.digits[i];
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        return result;
    }

    // Helper Function: Subtract Two Numbers
    static BigInteger subtract(const BigInteger& a, const BigInteger& b) {
        BigInteger result;
        int borrow = 0;
        for (size_t i = 0; i < a.digits.size(); i++) {
            int diff = a.digits[i] - borrow - (i < b.digits.size() ? b.digits[i] : 0);
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits.push_back(diff);
        }
        result.removeLeadingZeros();
        return result;
    }

    // Helper Function: Multiply Two Numbers
    static BigInteger multiply(const BigInteger& a, const BigInteger& b) {
        BigInteger result;
        result.digits.resize(a.digits.size() + b.digits.size(), 0);

        for (size_t i = 0; i < a.digits.size(); i++) {
            int carry = 0;
            for (size_t j = 0; j < b.digits.size() || carry; j++) {
                int temp = result.digits[i + j] +
                           a.digits[i] * (j < b.digits.size() ? b.digits[j] : 0) + carry;
                result.digits[i + j] = temp % 10;
                carry = temp / 10;
            }
        }
        result.removeLeadingZeros();
        return result;
    }

    // Helper Function: Absolute Value and Comparison
    static BigInteger absValue(const BigInteger& num) {
        BigInteger result = num;
        result.isNegative = false;
        return result;
    }

    static bool absLess(const BigInteger& a, const BigInteger& b) {
        if (a.digits.size() != b.digits.size()) return a.digits.size() < b.digits.size();
        for (int i = a.digits.size() - 1; i >= 0; i--) {
            if (a.digits[i] != b.digits[i]) return a.digits[i] < b.digits[i];
        }
        return false;
    }

    static bool absGreater(const BigInteger& a, const BigInteger& b) {
        return !absLess(a, b) && !(a == b);
    }

    static bool absGreaterOrEqual(const BigInteger& a, const BigInteger& b) {
        return absGreater(a, b) || (a == b);
    }
};

// Main Function to Test the Class
int main() {
    BigInteger a, b;
    cout << "Enter two large numbers:\n";
    cin >> a >> b;

    cout << "Sum: " << (a + b) << endl;
    cout << "Difference: " << (a - b) << endl;
    cout << "Product: " << (a * b) << endl;

    return 0;
}
