#include <iostream>
using namespace std;

class Matrix {
    private:
        int rows, cols;
        int** elements;

    public:
        Matrix(int r, int c) : rows(r), cols(c) {
            elements = new int*[rows];
            for (int i = 0; i < rows; i++) {
                elements[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    elements[i][j] = 0;  
                }
            }
        }

        Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
            elements = new int*[rows];
            for (int i = 0; i < rows; i++) {
                elements[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    elements[i][j] = other.elements[i][j];
                }
            }
        }

        Matrix& operator=(const Matrix& other) {
            if (this == &other) return *this; 

            for (int i = 0; i < rows; i++) {
                delete[] elements[i];
            }
            delete[] elements;

            rows = other.rows;
            cols = other.cols;
            elements = new int*[rows];
            for (int i = 0; i < rows; i++) {
                elements[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    elements[i][j] = other.elements[i][j];
                }
            }
            return *this;
        }

        int getRows() const {
            return rows;
        }

        int getCols() const {
            return cols;
        }

        void setElement(int i, int j, int value) {
            if (i >= 0 && i < rows && j >= 0 && j < cols) {
                elements[i][j] = value;
            } else {
                cout << "Invalid position!" << endl;
            }
        }

        void display() const {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << elements[i][j] << " ";
                }
                cout << endl;
            }
        }

        Matrix add(const Matrix& other) {
            if (rows != other.rows || cols != other.cols) {
                cout << "Matrices cannot be added" << endl;
                return Matrix(0, 0);
            }

            Matrix result(rows, cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result.elements[i][j] = elements[i][j] + other.elements[i][j];
                }
            }
            return result;
        }

        Matrix multiply(const Matrix& other) {
            if (cols != other.rows) {
                cout << "Matrices cannot be multiplied" << endl;
                return Matrix(0, 0);
            }

            Matrix result(rows, other.cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < other.cols; j++) {
                    result.elements[i][j] = 0;
                    for (int k = 0; k < cols; k++) {
                        result.elements[i][j] += elements[i][k] * other.elements[k][j];
                    }
                }
            }
            return result;
        }

        ~Matrix() {
            for (int i = 0; i < rows; i++) {
                delete[] elements[i];
            }
            delete[] elements;
        }
};

int main() {
    Matrix mat1(2, 2);
    Matrix mat2(2, 2);

    mat1.setElement(0, 0, 1);
    mat1.setElement(0, 1, 2);
    mat1.setElement(1, 0, 3);
    mat1.setElement(1, 1, 4);

    mat2.setElement(0, 0, 5);
    mat2.setElement(0, 1, 6);
    mat2.setElement(1, 0, 7);
    mat2.setElement(1, 1, 8);

    cout << "Matrix 1:" << endl;
    mat1.display();

    cout << "Matrix 2:" << endl;
    mat2.display();

    cout << "Addition Result:" << endl;
    Matrix addResult = mat1.add(mat2);
    addResult.display();

    cout << "Multiplication Result:" << endl;
    Matrix multiplyResult = mat1.multiply(mat2);
    multiplyResult.display();

    return 0;
}
