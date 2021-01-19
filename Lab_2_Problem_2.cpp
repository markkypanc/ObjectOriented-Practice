/*

 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 2
 Question No: 2
 Date: January 19, 2021

 -------------------------------------------------------------------------------
 
            [Objectives Overview] --> using vector!
 
            Ask user to enter value of rows and column to Matrix
            Find the minimum value of each row
            Display the result
 
 -------------------------------------------------------------------------------
 
 */

#include <iostream>
#include <vector>

int main(void)
{
    
    // User input
    int row, column;
    std::cout << "Enter a number of rows for your metrix: ";
    std::cin >> row;
    std::cout << "Enter a number of column for your metrix: ";
    std::cin >> column;
    
    // Declare a metrix
    std::vector<std::vector<int>> matrix;
    std::vector<int> temp;
    int number; // each item in nested vector
    
    // Collect the number to store in a nested matrix
    for (int i = 0 ; i < row; i++)
    {
        temp.clear();
        for (int j = 0; j < column; j++)
        {
            std::cout << "Enter the value for Matrix" << '[' << i << "][" << j << "]: ";
            std::cin >> number;
            temp.push_back(number);
        }
        matrix.push_back(temp);
    }
    
    // Print the matrix out
    std::cout << "\nThe value of the matrix you entered is...\n";
    for (int a = 0; a < matrix.size(); a++) // { [1], [2], [3], [4] }
    {
        for (int b = 0; b < matrix[a].size(); b++)
        {
            std::cout << matrix[a][b] << ' ';
        }
        std::cout << "\n";
    }
    
    // Sorted and show the minimum number of each row
    std::vector<std::vector<int>> copy = matrix;
    for (int m = 0; m < copy.size(); m++)
    {
        std::sort(copy[m].begin(), copy[m].end());
        std::cout << "The minimum number of row " << m + 1 << " is " << copy[m][0] << std::endl;
    }
    
    std::cout << "Good bye!\n\n";
}
