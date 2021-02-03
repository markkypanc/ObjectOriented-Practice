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

void askUserAndPrint(string length_prompt, string height_prompt, double *lengthPtr, double *heightPtr);
void triangleChoice(string base_prompt, string height_prompt, double *basePtr, double *heightPtr);
void rectangleChoice(string width_prompt, string height_prompt, double *widthPtr, double *heightPtr);
double getArea(double *widthPtr, double *heightPtr, int choice);

bool continued = true;

int main(int argc, char* argv[]) {
    
    double length;
    double height;
    double *lengthPtr = &length;
    double *heightPtr = &height;
    
    string lenght_prompt = "Enter length of a";
    string height_prompt = "Enter height of a";
    
    while (continued) {
        askUserAndPrint(lenght_prompt, height_prompt, lengthPtr, heightPtr);
    }
    
    return 0;
}

// ask user for either rectangle or triangle's dimensions
void askUserAndPrint(string length_prompt, string height_prompt, double *lengthPtr, double *heightPtr) {
    
    int decision;
    
    cout << "1) Triangle\n";
    cout << "2) Rectangle\n";
    cout << "0) Exit\n";
    cout << "Your choice: ";
    
    cin >> decision;
    
    switch (decision) {
        case 1:
            triangleChoice(length_prompt, height_prompt, lengthPtr, heightPtr);
            cout << "\nArea of the triangle is " << getArea(lengthPtr, heightPtr, 1) << " square units\n\n";
            break;
        case 2:
            rectangleChoice(length_prompt, height_prompt, lengthPtr, heightPtr);
            cout << "\nArea of the rectangle is " << getArea(lengthPtr, heightPtr, 2) << " square units\n\n";
            break;
        default:
            continued = false;
            return;
    }
}

// ask for triangle's base length and height
void triangleChoice(string base_prompt, string height_prompt, double *basePtr, double *heightPtr) {
    cout << base_prompt + " triangle: ";
    cin >> *basePtr;
    cout << height_prompt + " triangle: ";
    cin >> *heightPtr;
}

// ask for rectangle's width and length
void rectangleChoice(string width_prompt, string height_prompt, double *widthPtr, double *heightPtr) {
    cout << width_prompt + " rectangle: ";
    cin >> *widthPtr;
    cout << height_prompt + " rectangle: ";
    cin >> *heightPtr;
}

double getArea(double *widthPtr, double *heightPtr, int choice) {
    
    // Compute triangle
    if (choice == 1) {
        return (*widthPtr) * (*heightPtr) / 2;
    } else {
        return (*widthPtr) * (*heightPtr);
    }
}
