/*

 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 1
 Question No: 1
 Date: January 13, 2020

 -------------------------------------------------------------------------------
 
                            Pseudocode
                     
                     Ask user for market price and EPS
                     Calculate PE
 
                     If PE >= 30
                        overvalued
                     else if 30 > PE >= 10
                        OK
                     else
                        undervalued
 
 -------------------------------------------------------------------------------
 
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
    double market, eps;
    
    // Asking user for market price and EPS
    cout << "Enter market price and EPS of your stock separated by space: ";
    cin >> market >> eps;
    
    double price = market / eps;
    
    if (price >= 30)
    {
        cout << "The stock price is overvalued" << endl;
    }
    else if (price >= 10 && price < 30) // Range 10 to 30
    {
        cout << "The stock price is OK" << endl;
    }
    else
    {
        cout << "The stock price in undervalued" << endl;
    }
    
    return 0;
    
}
