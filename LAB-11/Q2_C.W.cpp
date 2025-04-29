#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class DimensionMismatchException : public exception {
    const char* what() const noexcept override {
        return "Matrix Dimension Mismatch!";
    }
};

template <typename T>
class Matrix {
    vector<vector<T>> mat;
    int rows, cols;
    public:
        Matrix(int r, int c) : rows(r), cols(c), mat(r, vector<T>(c)) {}

        void set(int r, int c, T val) {
            if (r >= rows || c >= cols) throw out_of_range("Invalid index");
            mat[r][c] = val;
        }

        T get(int r, int c) const {
            if (r >= rows || c >= cols) throw out_of_range("Invalid index");
            return mat[r][c];
        }

        Matrix operator+(const Matrix& other) {
            if (rows != other.rows || cols != other.cols)
                throw DimensionMismatchException();
            Matrix<T> result(rows, cols);
            for (int i = 0; i < rows; ++i)
                for (int j = 0; j < cols; ++j)
                    result.set(i, j, mat[i][j] + other.get(i, j));
            return result;
        }
};

int main() {
    Matrix<int> m1(2, 2), m2(2, 2);
    m1.set(0, 0, 1); m1.set(0, 1, 2);
    m2.set(0, 0, 3); m2.set(0, 1, 4);

    Matrix<int> result = m1 + m2;
    cout << "Sum at (0,0): " << result.get(0, 0) << endl;
    return 0;
}
