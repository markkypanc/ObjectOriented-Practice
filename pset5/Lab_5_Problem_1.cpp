/*

 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 4
 Question No: 1
 Date: February 10, 2021
 
 -------------------------------------------------------------------------------
 
            [Objectives Overview] -> use pointer
        Allow user to specify to perform whether a multiplication or addition
            If choice exit is chosen
                terminate
        Allow user to specify sizes
 
 -------------------------------------------------------------------------------x
 
 */

#include <iostream>
#include <string>
using namespace std;

int** createMatrix(int numRows, int numColumns);
void setMatrix(int **matrix, int numRows, int numColumns, char name);
void matrixAddition(int **matrixA, int **matrixB, int **matrixC, int numRows, int numColumns);
void matrixMultiplication(int **matrixA, int **matrixB, int **matrixC, int numRowsA, int numColumnsA, int numRowsB, int numColumnsB);
void printMatrix(int **myArray, int row, int column, char name);

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

        int **matrixA = createMatrix(numRowsA, numColumnsA);
        int **matrixB = createMatrix(numRowsB, numColumnsB);
        
        setMatrix(matrixA, numRowsA, numColumnsA, 'A');
        setMatrix(matrixB, numRowsB, numColumnsB, 'B');
        
        if (decision == 1) {
            int **matrixC = createMatrix(numRowsA, numColumnsA);
            matrixAddition(matrixA, matrixB, matrixC, numRowsA, numColumnsA);
            cout << endl;
            printMatrix(matrixC, numRowsA, numColumnsA, 'C');
            cout << endl;
        } else {
            int **matrixC = createMatrix(numRowsA, numColumnsB);
            matrixMultiplication(matrixA, matrixB, matrixC, numRowsA, numColumnsA, numRowsB, numColumnsB);
            cout << endl;
            printMatrix(matrixC, numRowsA, numColumnsB, 'C');
            cout << endl;
        }
    }
    
    return 0;
}

int** createMatrix(int numRows, int numColumns) {
    int** matrix = new int*[numRows];
    for (int i = 0; i < numRows; i++) {
        *(matrix + i) = new int[numColumns];
    }
    return matrix;
}

void setMatrix(int **matrix, int numRows, int numColumns, char name) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            cout << name << "[" << i+1 << "][" << j+1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int **myArray, int row, int column, char name) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << name << "[" << i << "][" << j << "] " << myArray[i][j] << "\t";
        }
        cout << endl;
    }
}

void freeMatrix(int **metrix, int numRows) {
    for (int i = 0; i < numRows; i++) {
        delete[] *(metrix + i);
    }
    delete[] metrix;
}

void matrixAddition(int **matrixA, int **matrixB, int **matrixC, int numRows, int numColumns) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void matrixMultiplication(int **matrixA, int **matrixB, int **matrixC, int numRowsA, int numColumnsA, int numRowsB, int numColumnsB) {
    for (int i = 0; i < numRowsA; i++)
    {
        for (int j = 0; j < numColumnsB; j++)
        {
            matrixC[i][j] = 0;
        }
    }
    for (int a = 0; a < numRowsA; a++)
    {
        for (int b = 0; b < numColumnsB; b++)
        {
            for (int c = 0; c < numColumnsA; c++)
            {
                matrixC[a][b] += matrixA[a][c] * matrixB[c][b];
            }
        }
    }
}
