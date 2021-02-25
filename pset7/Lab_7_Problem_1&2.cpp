/*

 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 7
 Question No: 1&2
 Date: February 23, 2021
 
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef class Matrix {
    
private:
    
    char name;
    vector<vector<int>> storedData;
    int rowsCount, columnsCount; // To improve readability and maintainability
    
public:
    
    Matrix(char name, int rows, int columns) {
        this->name = name;
        
        storedData.resize(rows);
        for (int i = 0; i < rows; i++) {
            storedData[i].resize(columns);
        }
        
        this->rowsCount = rows;
        this->columnsCount = columns;
    }
    
    ~Matrix() {
        for (int i = 0; i < storedData.size(); i++) {
            storedData[i].clear();
        }
        storedData.clear();
    }
    
    int getRowsCount() { // (1)
        return  this->rowsCount;
    }
    
    int getColumnsCount() { // (2)
        return this->columnsCount;
    }
    
    int getValueByIndex(int row, int column) { // (3)
        return this->storedData[row][column];
    }
    
    void setValueByIndex(int row, int column, int value) { // (4)
        this->storedData[row][column] = value;
    }
    
    void fillMatrixByUser() { // (5)
        int value;
        
        cout << "Matrix " << name << endl;
        
        for (int i = 0; i < storedData.size(); i++) {
            for (int j = 0; j < storedData[i].size(); j++) {
                cout << "Matrix" << name << "[" << i+1 << "][" << j+1 << "]: ";
                cin >> value;
                storedData[i][j] = value;
            }
        }
        cout << endl;
    }
    
    Matrix addMatrix(Matrix matrix) { // (6)
        
        Matrix result('C', this->rowsCount, this->columnsCount); // Copycat dimensional number
        
        for (int i = 0; i < result.getRowsCount(); i++) {
            for (int j = 0; j < result.getColumnsCount(); j++) {
                int selfValue = this->storedData[i][j];
                int operandValue = matrix.getValueByIndex(i, j);
                result.setValueByIndex(i, j, selfValue + operandValue);
            }
        }
        return result;
    }
    
    Matrix multiplyMatrix (Matrix matrix) { // (7)
        
        Matrix result('C', this->rowsCount, matrix.getColumnsCount());
        
        for (int i = 0; i < this->rowsCount; i++)
        {
            for (int j = 0; j < matrix.getColumnsCount(); j++)
            {
                result.storedData[i][j] = 0;
            }
        }
        for (int a = 0; a < this->rowsCount; a++)
        {
            for (int b = 0; b < matrix.getColumnsCount(); b++)
            {
                for (int c = 0; c < this->columnsCount; c++)
                {
                    result.storedData[a][b] += matrix.storedData[c][b] * this->storedData[a][c];
                }
            }
        }
        
        return result;
        
    }
    
    void printMatrix() {
        cout << "Matrix " << name << endl;
        for (int i = 0; i < this->rowsCount; i++) {
            for (int j = 0; j < this->columnsCount; j++) {
                cout << name << "[" << i+1 << "][" << j+1 << "] " << this->storedData[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    
} Matrix;


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
        
        int numRowsA, numColumnsA;
        int numRowsB, numColumnsB;
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

        // Matrix initialization
        Matrix matrixA('A', numRowsA, numColumnsA);
        Matrix matrixB('B', numRowsB, numColumnsB);
        
        matrixA.fillMatrixByUser();
        matrixB.fillMatrixByUser();
        
        matrixA.printMatrix();
        matrixB.printMatrix();
        
        if (decision == 1) {
            Matrix matrixC = matrixA.addMatrix(matrixB);
            matrixC.printMatrix();
        } else {
            Matrix matrixC = matrixA.multiplyMatrix(matrixB);
            matrixC.printMatrix();
        }
    }
    return 0;
}
