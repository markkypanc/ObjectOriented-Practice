/*

 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 4
 Question No: 1
 Date: February 3, 2021
 
 -------------------------------------------------------------------------------
 
            [Objectives Overview] --> Passing by references
 
 -------------------------------------------------------------------------------x
 
 */

#include <iostream>
#include <string>
using namespace std;

void askUserAndPrint(string length_prompt, string height_prompt, double &length, double &height);
void triangleChoice(string base_prompt, string height_prompt, double &base, double &height);
void rectangleChoice(string width_prompt, string height_prompt, double &width, double &height);
double getArea(double &width, double &height, int choice);

bool continued = true;

int main(int argc, char* argv[]) {
    double length;
    double height;
    string lenght_prompt = "Enter length of a";
    string height_prompt = "Enter height of a";
    
    while (continued) {
        askUserAndPrint(lenght_prompt, height_prompt, length, height);
    }
    
    return 0;
}

// ask user for either rectangle or triangle's dimensions
void askUserAndPrint(string length_prompt, string height_prompt, double &length, double &height) {
    
    int decision;
    
    cout << "1) Triangle\n";
    cout << "2) Rectangle\n";
    cout << "0) Exit\n";
    cout << "Your choice: ";
    
    cin >> decision;
    
    // Control flow
    switch (decision) {
        case 1:
            triangleChoice(length_prompt, height_prompt, length, height);
            cout << "\nArea of the triangle is " << getArea(length, height, 1) << " square units\n\n";
            break;
        case 2:
            rectangleChoice(length_prompt, height_prompt, length, height);
            cout << "\nArea of the rectangle is " << getArea(length, height, 2) << " square units\n\n";
            break;
        default:
            return;
    }
}

// ask for triangle's base length and height
void triangleChoice(string base_prompt, string height_prompt, double &base, double &height) {
    cout << base_prompt + " triangle: ";
    cin >> base;
    cout << height_prompt + " triangle: ";
    cin >> height;
}

// ask for rectangle's width and length
void rectangleChoice(string width_prompt, string height_prompt, double &width, double &height) {
    cout << width_prompt + " rectangle: ";
    cin >> width;
    cout << height_prompt + " rectangle: ";
    cin >> height;
}

double getArea(double &width, double &height, int choice) {
    
    // Compute triangle
    if (choice == 1) {
        return (width * height) / 2;
    } else {
        return width * height;
    }
}
