/*

 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 4
 Question No: 2
 Date: February 3, 2021
 
 -------------------------------------------------------------------------------
 
            [Objectives Overview] --> Pointers required
 
 -------------------------------------------------------------------------------x
 
 */

#include <iostream>
#include <string>

using namespace std;

void askUserAndPrint(double *lengthPtr, double *widthPtr);
void triangleChoice(string base_prompt, string height_prompt, double *basePtr, double *heightPtr);
void rectangleChoice(string width_prompt, string height_prompt, double *widthPtr, double *heightPtr);
double getArea(double *widthPtr, double *heightPtr, int choice);

bool runningStatus = true;

int main(int argc, char* argv[]) {
    
    double length;
    double height;
    
    while (runningStatus) { // [1]
        askUserAndPrint(&length, &height);
    }
    
    return 0;
}

// ask user for either rectangle or triangle's dimensions
void askUserAndPrint(double *Ptr1, double *Ptr2) {
    
    int decision;
    
    cout << "1) Triangle\n";
    cout << "2) Rectangle\n";
    cout << "0) Exit\n";
    cout << "Your choice: ";
    
    cin >> decision;
    
    switch (decision) {
        case 1: {
            string baseStr = "Enter the base length of the triangle: ";
            string heightStr = "Enter the height of the triangle: ";
            triangleChoice(baseStr, heightStr, Ptr1, Ptr2);
            cout << "\nArea of the triangle is " << getArea(Ptr1, Ptr2, 1) << " square units\n\n";
            break;
        }
        case 2: {
            string widthStr = "Enter the width of the rectangle: ";
            string lengthStr = "Enter the length of the rectangle: ";
            rectangleChoice(widthStr, lengthStr, Ptr1, Ptr2);
            cout << "\nArea of the rectangle is " << getArea(Ptr1, Ptr2, 2) << " square units\n\n";
            break;
        }
        default: {
            runningStatus = false;
            return;
        }
    }
}

// ask for triangle's base length and height
void triangleChoice(string base_prompt, string height_prompt, double *basePtr, double *heightPtr) {
    cout << base_prompt;
    cin >> *basePtr;
    cout << height_prompt;
    cin >> *heightPtr;
}

// ask for rectangle's width and length
void rectangleChoice(string width_prompt, string height_prompt, double *widthPtr, double *lengthPtr) {
    cout << width_prompt;
    cin >> *widthPtr;
    cout << height_prompt;
    cin >> *lengthPtr;
}

double getArea(double *Ptr1, double *Ptr2, int choice) {
    
    // Compute triangle
    if (choice == 1) {
        return (*Ptr1) * (*Ptr2) / 2;
    } else {
        return (*Ptr1) * (*Ptr2);
    }
}
