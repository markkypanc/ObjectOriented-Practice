/*
 
 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 8
 Question No: 2
 Date: March 9, 2021
 
 */

#include <iostream>
using namespace std;

// MARK: - RectangleClass

class Rectangle {
    
private:
    
    double width, length;
    
public:
    
    // Default constructor (2.1)
    Rectangle() {
        this->width = 0;
        this->length = 0;
    }
    
    // Constructor with 2 parameters (2.2)
    Rectangle(int width, int length) {
        this->width = width;
        this->length = length;
    }
    
    void setWidth(int aWidth) {
        width = aWidth;
    }
    
    void setLength(int aLength) {
        length = aLength;
    }
    
    double getWidth() const {
        return width;
    }
    
    double getLength() const {
        return length;
    }
    
    double getArea() const {
        return width * length;
    }
};

// MARK: - BoxClass (2.4)

class Box: public Rectangle {
    
private:
    
    int height;
    
public:
    
    // Setter (2.4.2)
    void setHeight(int height) {
        this->height = height;
    }
    
    // Getter (2.4.3)
    int getHeight() {
        return this->height;
    }
    
    // Default constrctor
    Box() {
        Rectangle();
    }
    
    // Constructor with init parameters
    Box(int width, int length, int height) {
        setWidth(width);
        setLength(length);
        this->height = height;
    }
    
    // Override methods
    int getArea() {
        return 2 * (getLength() * getWidth() + getLength() * getHeight() + getWidth() * getHeight());
    }
    
    int getVolume() {
        return getWidth() * getLength() * getHeight();
    }
};

// MARK: - UtilityClass

class PrintRectangleShape {

public :
    
    static void printAreaInfo(Rectangle rectangle) {
        cout << "Area of the rectangle with ratio w:h = " << rectangle.getWidth() << ':' << rectangle.getLength() << " is " << rectangle.getArea() << endl << endl;
    }
    
    static void printAreaInfo(Box box) {
        cout << "Surface area of the box with ratio w:l:h = " << box.getWidth() << ':' << box.getLength() << ':' << box.getHeight() << " is " << box.getArea() << endl;
    }
    
    static void printVolumInfo(Box box) {
        cout << "Volume of the box with ratio w:l:h = " << box.getWidth() << ':' << box.getLength() << ':' << box.getHeight() << " is " << box.getVolume() << endl << endl;
    }
};

// MARK: - MAIN

int main(int argc, char* argv[]) {
    
    while (true) {
        cout << "1) Rectangle" << endl;
        cout << "2) Box" << endl;
        cout << "0) Exit" << endl;
        
        int decision;
        
        cout << "Your choice: ";
        cin >> decision;
        
        int width, length, height;
        
        switch (decision) {
            case 1:
            {
                cout << "Enter the width of the rectangle: ";
                cin >> width;
                cout << "Enter the length of the rectangle: ";
                cin >> length;
                cout << endl;
                
                Rectangle rectangle(width, length);
                PrintRectangleShape::printAreaInfo(rectangle);
                break;
            }
            case 2:
            {
                cout << "Enter the width of the box: ";
                cin >> width;
                cout << "Enter the length of the box: ";
                cin >> length;
                cout << "Enter the height of the box: ";
                cin >> height;
                cout << endl;
                
                Box box(width, length, height);
                PrintRectangleShape::printAreaInfo(box);
                PrintRectangleShape::printVolumInfo(box);
                break;
            }
            default:
            {
                cout << "Program has been terminated...\n\n";
                exit(0);
                break;
            }
        }
    }
    
}
