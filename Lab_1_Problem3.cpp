/*

 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 1
 Question No: 3
 Date: January 13, 2020

 -------------------------------------------------------------------------------
 
                            Pseudocode
                    Ask user for a positive radius
                        if negative, then repeat
                    Calculate and show the circle area
 
 -------------------------------------------------------------------------------
 
 */

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    double radius;
    
    do // Guard a case of nagative value input
    {
        cout << "Please enter the radius of the circle in positive value: ";
        cin >> radius;
    }
    while(radius<0);
    
    double area = M_PI * pow(radius, 2);
    cout << "\nThe area of the circle with radius equals " << radius << " is " << area << "\nGoodbye\n\n";
    
    return  0;
}
