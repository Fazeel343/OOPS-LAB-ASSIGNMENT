#include <iostream>
using namespace std;

class Matrix {
        int rows, cols;
        double** data;
    public:
        Matrix() : rows(0), cols(0), data(nullptr) {}
        Matrix(int r, int c) : rows(r), cols(c) {
            data = new double*[rows];
            for (int i = 0; i < rows; ++i) {
                data[i] = new double[cols]();
            }
        }
        Matrix(const Matrix& other) : Matrix(other.rows, other.cols) {
            for (int i = 0; i < rows; ++i)
                for (int j = 0; j < cols; ++j)
                    data[i][j] = other.data[i][j];
        }
        Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), data(other.data) {
            other.data = nullptr;
        }
        ~Matrix() {
            for (int i = 0; i < rows; ++i) delete[] data[i];
            delete[] data;
        }
        int getRows() const { return rows; }
        int getCols() const { return cols; }
        double& at(int r, int c) { return data[r][c]; }
        void fill(double value) {
            for (int i = 0; i < rows; ++i)
                for (int j = 0; j < cols; ++j)
                    data[i][j] = value;
        }
        Matrix transpose() {
            cout << "Transposed Matrix:" << endl;
            Matrix trans(cols, rows);
            for (int i = 0; i < rows; ++i)
                for (int j = 0; j < cols; ++j)
                    trans.data[j][i] = data[i][j];
            cout << "Transposed Matrix." << endl;
            for ( int i=0; i< trans.getRows(); i++) {
                for (int j=0; j< trans.getCols(); j++) {
                    cout << trans.data[i][j] << " ";
                }
                cout << endl;
            }
            return trans;
        }
};

int main() {
    int rows, cols;
    double value;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    cout << "Enter value to fill the matrix: ";
    cin >> value;

    Matrix mat(rows, cols); 
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double value;
            cout << "Enter value for position (" << i << ", " << j << "): ";
            cin >> value;
            mat.at(i, j) = value;
        }
    }


    Matrix transposed = mat.transpose(); 
    return 0;
}
