/*

 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 1
 Question No: 2
 Date: January 13, 2020

 -------------------------------------------------------------------------------
 
                            Pseudocode
                     
                    Ask user how many number
                    If number is not positive
                        return 1
                    Repeat input times
                        accumulate an amount
                    Calculate and show an average value
 
 -------------------------------------------------------------------------------
 
 */

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int number;
    cout << "How many number in your list: ";
    cin >> number;
    
    if (number <= 0)
    {
        cout << "You enter 0 or negative number, the average value cannot be calculated, goodbye!\n";
        return 1;
    }
    
    double item;
    double total = 0;
    for (int i = 1; i <= number; i++) // Collect a number refer to a user input
    {
        cout << "Round " << i << " enter a number: ";
        cin >> item;
        total += item;
    }
    
    // show the value to a debugger
    double average = total / number;
    cout << "\nThe average is " << average << '\n' << "Goodbye!\n\n";
    
    return  0;
}
