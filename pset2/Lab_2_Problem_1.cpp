/*

 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 2
 Question No: 1
 Date: January 19, 2021

 -------------------------------------------------------------------------------
 
            [Objectives Overview] --> using only an array!
 
            Ask user to enter value to Matrix
            Ask them to specify the dimension that can not exceed 5 x 5
            Find the minimum value of each row
            Display the result
 
 -------------------------------------------------------------------------------
 
 */

#include <iostream>

int main(void)
{
    
    int row = 0, column = 0;
    bool isRowAccepted = false;
    
    // Get row for the Matrix
    while (true) {
        if (!isRowAccepted)
        {
            std::cout << "Enter number of rows for your matrix: ";
            std::cin >> row;
            if (row > 5) // Guard for a row input error first
            {
                std::cout << "The limit of a row number is 5...\n";
                continue; // Loop until the input is correct
            }
            isRowAccepted = true;
            continue;
        }
        else
        {
            std::cout << "Enter number of columns for your matrix: ";
            std::cin >> column;
            if (column > 5) // Guard for an input errors
            {
                std::cout << "The limit of a column number is 5...\n";
                continue;
            }
            break;
        }
    } // end of while loop
    
    int matrix[row][column];
    int storeMin[row];
    int min = 0;
    
    // Ask for a value of each metrix space
    for (int i = 0; i < row ; i++) // Row
    {
        for (int j = 0; j < column; j++) // Column
        {
            std::cout << "Enter the value for Matrix" << '[' << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
            if (j == 0) // Catch the first number of each row
            {
                min = matrix[i][0];
            }
            else // The elements from 1 to the end
            {
                if (matrix[i][j] < min)
                {
                    min = matrix[i][j];
                }
            }
        }
        
        storeMin[i] = min; // Add the minimum number to a stored array
        
    }
    
    // Print the table of the Matrix
    std::cout << "\nThe value of the matrix you entered is...\n";
    for (int a = 0; a < row; a++)
    {
        for (int b = 0; b < column; b++)
        {
            std::cout << matrix[a][b] << ' ';
        }
        std::cout << "\n";
    }
    
    // Show a minimum number from each row
    std::cout << "\nThe minimum number in each row is as follows...\n";
    for (int rows = 0; rows < row; rows++)
    {
        std::cout << "A minimum number of row " << rows + 1 << " is " << storeMin[rows] << std::endl;
    }
    
    std::cout << "Good bye!\n\n";
}
