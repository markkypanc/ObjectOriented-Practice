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

void askUserAndPrint();
void triangleChoice(string base_prompt, string height_prompt, double &base, double &height);
void rectangleChoice(string width_prompt, string height_prompt, double &width, double &height);
double getArea(double &width, double &height, int choice);

bool runningStatus = true;

int main(int argc, char* argv[]) {
    double length;
    double height;
    string lenght_prompt = "Enter ";
    string height_prompt = "Enter ";
    
    while (runningStatus) {
        askUserAndPrint();
    }
    
    return 0;
}

// ask user for either rectangle or triangle's dimensions
void askUserAndPrint() {
    
    int decision;
    
    cout << "1) Triangle\n";
    cout << "2) Rectangle\n";
    cout << "0) Exit\n";
    cout << "Your choice: ";
    
    cin >> decision;
    
    double height;
    
    // Control flow
    switch (decision) {
        case 1: {
            string baseStr = "Enter the base length of the triangle: ";
            string heightStr = "Enter the height of the triangle: ";
            double length;
            triangleChoice(baseStr, heightStr, length, height);
            cout << "\nArea of the triangle is " << getArea(length, height, 1) << " square units\n\n";
            break;
        }
        case 2: {
            string widthStr = "Enter the width of the rectangle: ";
            string lengthStr = "Enter the length of the rectangle: ";
            double width;
            rectangleChoice(widthStr, lengthStr, width, height);
            cout << "\nArea of the rectangle is " << getArea(width, height, 2) << " square units\n\n";
            break;
        }
        default: {
            runningStatus = false;
            return;
        }
    }
}

// ask for triangle's base length and height
void triangleChoice(string base_prompt, string height_prompt, double &base, double &height) {
    cout << base_prompt;
    cin >> base;
    cout << height_prompt;
    cin >> height;
}

// ask for rectangle's width and length
void rectangleChoice(string width_prompt, string height_prompt, double &width, double &height) {
    cout << width_prompt;
    cin >> width;
    cout << height_prompt;
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
