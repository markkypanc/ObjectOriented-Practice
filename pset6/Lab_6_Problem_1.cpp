/*

 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 6
 Question No: 1
 Date: February 16, 2021

 */

#include <iostream>
#include <string>
using namespace std;

typedef class Matrix {
    
private:
    
    char name;
    int row;
    int cols;
    int **node;
    
public:
    
    void init(char name, int row, int cols) {
        this->name = name;
        this->row = row;
        this->cols = cols;
    }
    
    // Set the private node: memory allocation
    void setMatrixDimension(int numRows, int numCols) {
        node = new int*[numRows];
        for (int i = 0; i < numRows; i++) {
            *(node + i) = new int[numCols];
        }
    }

    // Set the private node: set internal number in matrix
    void setMatrixByIndex(int rowIndex, int colIndex, int value) {
        node[rowIndex][colIndex] = value;
    }
      
    // for showing the number eventually
    int getMatrixByIndex(int rowIndex, int colIndex) {
        return node[rowIndex][colIndex];
    }
    
    int getRow() {
        return row;
    }
    
    int getCols() {
        return cols;
    }
    
    Matrix addMatrix(Matrix matrix) {
        
        Matrix result;
        result.setMatrixDimension(row, cols);
        result.init('C', row, cols);
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < cols; j++) {
                result.node[i][j] = matrix.node[i][j] + node[i][j];
            }
        }
        return result;
    }
    
    Matrix multiplyMatrix (Matrix matrix) {
        
        Matrix result;
        result.setMatrixDimension(row, cols);
        result.init('C', row, matrix.getCols());
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < matrix.getCols(); j++)
            {
                result.node[i][j] = 0;
            }
        }
        for (int a = 0; a < row; a++)
        {
            for (int b = 0; b < matrix.getCols(); b++)
            {
                for (int c = 0; c < cols; c++)
                {
                    result.node[a][b] += matrix.node[c][b] * node[a][c];
                }
            }
        }
        
        return result;
        
    }
    
    void printMatrix() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < cols; j++) {
                cout << name << "[" << i << "][" << j << "] " << node[i][j] << "\t";
            }
            cout << endl;
        }
    }
    
    void deleteMatrix() {
        for (int i = 0; i < row; i++) {
            delete[] *(node + i);
        }
        delete[] node;
    }
    
} Matrix;

// Function declaration
void askUser(Matrix matrix, char name);

int main(int argc, char* argv[]) {
    
    while (true) {
        
        int decision;
        
        cout << "1) Matrix Addition\n";
        cout << "2) Matrix Multiplication\n";
        cout << "3) Exit\n";
        cout << "Your choice: ";
        
        cin >> decision;
        
        // Guard the condition if user wants to quit
        if (decision != 1 and decision != 2) {
            cout << "\nThe program has terminated...\n\n";
            exit(1);
        }
        
        int numRowsA, numColumnsA, numRowsB, numColumnsB;
        cout << "Enter rows and colums of Matrix A: ";
        cin >> numRowsA >> numColumnsA;
        cout << "Enter rows and colums of Matrix B: ";
        cin >> numRowsB >> numColumnsB;
        
        // Guard the mathematical error
        if (decision == 1 and (numRowsA != numRowsB or numColumnsA != numColumnsB)) {
            cout << "\nMatrix can not perform addition since the dimension are not matched...";
            cout << "please try again\n\n";
            continue;
        } else if (decision == 2 and (numRowsA != numColumnsB or numRowsB != numColumnsA)) {
            cout << "\nMatrix can not perform multiplication since their rows and colums are not matched...";
            cout << "please try again\n\n";
            continue;
        }

        Matrix matrixA;
        Matrix matrixB;
        matrixA.init('A', numRowsA, numColumnsA);
        matrixB.init('B', numRowsB, numColumnsB);
        
        matrixA.setMatrixDimension(numRowsA, numColumnsA); // memory allocated
        matrixB.setMatrixDimension(numRowsB, numColumnsB); // memory allocated
        
        askUser(matrixA, 'A'); // store values
        askUser(matrixB, 'B'); // store values
        
        if (decision == 1) {
            Matrix matrixC = matrixA.addMatrix(matrixB);
            cout << endl;
            matrixA.printMatrix();
            cout << "---------------------\n";
            matrixB.printMatrix();
            cout << "---------------------\n";
            matrixC.printMatrix();
            matrixC.deleteMatrix();
            cout << endl;
        } else {
            Matrix matrixC = matrixA.multiplyMatrix(matrixB);
            cout << endl;
            matrixA.printMatrix();
            cout << "---------------------\n";
            matrixB.printMatrix();
            cout << "---------------------\n";
            matrixC.printMatrix();
            matrixC.deleteMatrix();
            cout << endl;
        }
    }
    return 0;
}

void askUser(Matrix matrix, char name) {
    int value;
    cout << "Matrix " << name << endl;
    for (int i = 0; i < matrix.getRow(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            cout << "Matrix" << name << "[" << i << "][" << j << "]: ";
            cin >> value;
            matrix.setMatrixByIndex(i, j, value);
        }
    }
    cout << endl;
}
