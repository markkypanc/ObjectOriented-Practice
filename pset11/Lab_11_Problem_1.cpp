/*
 
 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 11
 Question No: 1
 Date: April 1, 2021
 
 */

#include <iostream>
#include <memory>
using namespace std;

//MARK: - MATRIX
class Matrix {
    
    //MARK: - PROPERTIES
private:
    int rows;
    int cols;
    unique_ptr<int[]>data; // CHANGES
    
    //MARK: - METHODS
public:
    
    // CONSTRUCTOR
    Matrix(int row = 0, int col = 0) {
        this->rows = row;
        this->cols = col;
        this->data = nullptr;
        
        setDimension(row, col);
    }
    
    //MARK: - COPY CONSTRUCTOR
    Matrix(const Matrix& obj) {
        this->rows = obj.rows;
        this->cols = obj.cols;
        
        setDimension(obj.getRows(), obj.getCols());
        
        for (int i = 0; i < obj.getRows(); i++) {
            for (int j = 0; j < obj.getCols(); j++) {
                setData(i, j, obj.getData(i, j));
            }
        }
    }
    
    //MARK: - OVERLOAD ASSIGNMENT OPERATOR
    Matrix& operator=(const Matrix& other) {
        
        setDimension(other.getRows(), other.getCols());
        
        for (int i = 0; i < other.getRows(); i++) {
            for (int j = 0; j < other.getCols(); j++) {
                setData(i, j, other.getData(i, j));
            }
        }
        return *this;
    }
    
    //MARK: - SETTER
    void setDimension(int aRows, int aCols) {
        if (aRows > 0 && aCols > 0) {
            data = make_unique<int[]>(aRows * aCols); // CHANGES
            rows = aRows;
            cols = aCols;
        } else {
            rows = 0;
            cols = 0;
            data = nullptr;
        }
    }
    
    void setData(int i, int j, int val) {
        data[((i)*cols) + j] = val;
    }
    
    //MARK: - GETTER
    int getData(int i, int j) const {
        return data[((i)*cols) + j];
    }
    
    int getRows() const {
        return rows;
    }
    int getCols() const {
        return cols;
    }
    
    // SUMMATION
    Matrix addMatrix(const Matrix& adder) {
        Matrix result;
        int rows = getRows(), cols = getCols();
        if (adder.getRows() == rows && adder.getCols() == cols) {
            result.setDimension(rows, cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result.setData(i, j, getData(i, j) + adder.getData(i, j));
                }
            }
        }
        return result;
    }
    
    // MULTIPLICATION
    Matrix multiplyMatrix(const Matrix& matrix) {
        Matrix result;
        int rows = getRows(), cols = getCols(), value;
        if (cols == matrix.getRows()) {
            result.setDimension(rows, matrix.getCols());
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < matrix.getCols(); ++j) {
                    value = 0;
                    for (int k = 0; k < cols; k++) {
                        value += getData(i, k) * matrix.getData(k, j);
                    }
                    result.setData(i, j, value);
                }
            }
        }
        return result;
    }
    
    // Set internal values
    void setMatrixValue(const string matName) {
        int value;
        for (int i = 0; i < getRows(); i++) {
            for (int j = 0; j < getCols(); j++) {
                cout << matName << "[" << i + 1 << "][" << j + 1 << "] ";
                cin >> value;
                setData(i, j, value);
            }
        }
        cout << endl;
    }
    
    // Output
    void displayMatrix(const string name) {
        int value;
        cout << "-----------------------" << endl;
        for (int i = 0; i < getRows(); ++i) {
            for (int j = 0; j < getCols(); ++j) {
                value = getData(i, j);
                cout << name << "[" << i + 1 << "]" << "[" << j + 1 << "] " << value << " ";
            }
            cout << endl;
        }
    }//: DISPLAY
};


//MARK: - DECLARATION
void summation();
void multiplication();

//MARK: - RUN
int main() {
    int choice;
    do {
        cout << "1.Matrix Addition\n2.Matrix Multiplication\n0.Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            summation();
            break;
        case 2:
            multiplication();
            break;
        case 0:
            break;
        default:
            cout << "Invalid input.\n\n";
        }
    } while (choice != 0);
    cout << "Program has teminated.\n\n";
    return 0;
};

void summation() {
    int rowsA, colsA, rowsB, colsB;
    
    string error = "Error! Matrix A and B must have the same dimension to perform the addition";
    
    cout << "Matrix A dimension: ";
    cin >> rowsA >> colsA;
    cout << "Matrix B dimension: ";
    cin >> rowsB >> colsB;
    
    if ((rowsA == rowsB) && (colsA == colsB)) {
        
        Matrix matA(rowsA, colsA), matB(rowsB, colsB);
        
        matA.setMatrixValue("A");
        matB.setMatrixValue("B");
        
        Matrix matC = matA.addMatrix(matB);
        
        if (matC.getRows() > 0) {
            matA.displayMatrix("A");
            matB.displayMatrix("B");
            matC.displayMatrix("C");
        } else {
            cout << error << endl;
        }//: IF MATRIX_C FATAL
        
    } else {
        cout << error << endl;
    }//: IF DIMENTIONAL ERROR OCCURED

}

void multiplication() {
    int rowsA, colsA, rowsB, colsB;
    string error = "Error! Matrix A and B dimensions do not match to perform the multiplication";
    
    cout << "Matrix A dimension: ";
    cin >> rowsA >> colsA;
    cout << "Matrix B dimension: ";
    cin >> rowsB >> colsB;
    
    if (colsA == rowsB) {
        Matrix matA(rowsA, colsA), matB(rowsB, colsB);
        
        matA.setMatrixValue("A");
        matB.setMatrixValue("B");
        
        Matrix matC = matA.multiplyMatrix(matB);
        
        if (matC.getRows() > 0) {
            matA.displayMatrix("A");
            matB.displayMatrix("B");
            matC.displayMatrix("C");
        }
        else {
            cout << error << endl;
        }//: IF MATRIX_C FATAL
    } else {
        cout << error << endl;
    }//: IF DIMENTIONAL ERROR OCCURED
}
