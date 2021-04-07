/*

 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 12
 Question No: 1
 Date: April 7, 2021
 
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//MARK: - MATRIX
class Matrix {
    
    //MARK: - PROPERTIES
private:
    char name;
    vector<vector<int>> storedData;
    int rowsCount, columnsCount;
    

    //MARK: - METHODS
public:
   
    // CONSTRUCTOR
    Matrix(char name, int rows, int columns) {
        this->name = name;
        
        storedData.resize(rows);
        for (int i = 0; i < rows; i++) {
            storedData[i].resize(columns);
        }
        
        this->rowsCount = rows;
        this->columnsCount = columns;
    }
    
    // DESTRUCTOR
    ~Matrix() {
        for (int i = 0; i < storedData.size(); i++) {
            storedData[i].clear();
        }
        storedData.clear();
    }
    
    //MARK: - GETTER
    
    char getName() {
        return this->name;
    }
    
    int getRowsCount() {
        return this->rowsCount;
    }
    
    int getColumnsCount() {
        return this->columnsCount;
    }
    
    int getValueByIndex(int row, int column) {
        return this->storedData[row][column];
    }
    
    vector<vector<int>> getMetrix() {
        return this->storedData;
    }
    
    //MARK: - SETTER
    
    void setValueByIndex(int row, int column, int value) {
        this->storedData[row][column] = value;
    }
    
    void fillMatrixByUser() {
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
    
    //MARK: - MATHEMATICAL PERFORMING
    
    Matrix addMatrix(Matrix &matrix) {
        
        Matrix result('C', this->rowsCount, this->columnsCount);
        
        for (int i = 0; i < result.getRowsCount(); i++) {
            for (int j = 0; j < result.getColumnsCount(); j++) {
                int selfValue = this->storedData[i][j];
                int operandValue = matrix.getValueByIndex(i, j);
                result.setValueByIndex(i, j, selfValue + operandValue);
            }
        }
        return result;
    }//: ADDING
    
    Matrix multiplyMatrix (Matrix &matrix) {
        
        Matrix result('C', this->rowsCount, matrix.getColumnsCount());
        
        for (int i = 0; i < this->rowsCount; i++) {
            for (int j = 0; j < matrix.getColumnsCount(); j++) {
                result.storedData[i][j] = 0;
            }
        }
        
        for (int a = 0; a < this->rowsCount; a++) {
            for (int b = 0; b < matrix.getColumnsCount(); b++) {
                for (int c = 0; c < this->columnsCount; c++) {
                    result.storedData[a][b] += matrix.storedData[c][b] * this->storedData[a][c];
                }
            }
        }
        
        return result;
        
    }//: MULTIPLYING
    
    
    //MARK: - OPERATOR OVERLOADING
    
    Matrix operator + (Matrix &matrix) {
        return addMatrix(matrix);
    }
    
    Matrix operator * (Matrix &matrix) {
        return multiplyMatrix(matrix);
    }
    
};//: MATRIX



//MARK: - INPUT OUTPUT STREAM OVERLOAD

ostream& operator << (ostream &out, Matrix &matrix) {
    
    char name = matrix.getName();
    int row = matrix.getRowsCount();
    int columns = matrix.getColumnsCount();
    
    out << "Matrix " << name << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < columns; j++) {
            out << matrix.getMetrix()[i][j] << " ";
        }
        out << endl;
    }
    out << endl;
    
    return out;
}

istream& operator >> (istream &in, Matrix &matrix) {
    
    int value;
    
    cout << "Matrix " << matrix.getName() << endl;
    
    for (int i = 0; i < matrix.getMetrix().size(); i++) {
        for (int j = 0; j < matrix.getMetrix()[i].size(); j++) {
            cout << "Matrix" << matrix.getName() << "[" << i+1 << "][" << j+1 << "]: ";
            in >> value;
            matrix.setValueByIndex(i, j, value);
        }
    }
    cout << endl;
    
    return in;
}

//MARK: - ERROR EXCEPTION CLASS

class FatalError: public exception {
private:
    string error = "Matrix dimension mismatch for the operation";
public:
    string getFatalError() {
        return this->error;
    }
};//: FATAL


//MARK: - TO RUN

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
        
        
        //MARK: - GUARD ERRORS
        try {
            if (decision == 1 and (numRowsA != numRowsB or numColumnsA != numColumnsB)) {
                throw string("\nMatrix can not perform addition since the dimension are not matched...\n");
            } else if (decision == 2 and (numRowsA != numColumnsB or numRowsB != numColumnsA)) {
                throw string("\nMatrix can not perform multiplication since their rows and colums are not matched...");
            }
        } catch (string error) {
            cout << error;
            continue;
        }//: FATALS

        // Matrix initialization
        Matrix matrixA('A', numRowsA, numColumnsA);
        Matrix matrixB('B', numRowsB, numColumnsB);
        
        // Get input
        cin >> matrixA;
        cin >> matrixB;
        
        // Show output
        cout << matrixA;
        cout << matrixB;
        
        if (decision == 1) {
            Matrix matrixC = matrixA + matrixB;
            cout << matrixC;
        } else {
            Matrix matrixC = matrixA * matrixB;
            cout << matrixC;
        }
    }
    return 0;
}
