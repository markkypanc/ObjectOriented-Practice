/*

 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 7
 Question No: 3
 Date: February 23, 2021
 
 */

#include <iostream>
#include <string>
#include <math.h>
using namespace std;


// Class 1
class Circle {
    double radius;
    double area;
    
public:
    Circle(double r) {
        this->radius = r;
    }
    
    double getArea() {
        return M_PI * pow(this->radius, 2);
    }
    
    double getRadius() {
        return this->radius;
    }
    
};


// Class 2
class Rectangle {
    double width;
    double height;
    
public:
    Rectangle(double width, double height) {
        this->width = width;
        this->height = height;
    }
    
    double getArea() {
        return this->width * this->height;
    }
    
    double getWidth() {
        return this->width;
    }
    
    double getHeight() {
        return this->height;
    }
};

    
// Class 3
class Triangle {
    double base;
    double height;
    
public:
    Triangle(double base, double height) {
        this->base = base;
        this->height = height;
    }
    
    double getArea() {
        return (this->base * this->height) / 2.0;
    }
    
    double getBase() {
        return this->base;
    }
    
    double getHeight() {
        return this->height;
    }
};


class PrintShape {
public:
    static void printArea(Circle circle) {
        double radius = circle.getRadius();
        double area = circle.getArea();
        cout << "Area of a circle with radius of " << radius << " is " << area << endl;
    }
    
    static void printArea(Rectangle rectangle) {
        double width = rectangle.getWidth();
        double height = rectangle.getHeight();
        cout << "Area of a rectangle with " << width << " width and " << height << " height is ";
        cout << width * height << endl;
    }
    
    static void printArea(Triangle triangle) {
        double base = triangle.getBase();
        double height = triangle.getHeight();
        double area = triangle.getArea();
        cout << "Area of a triangle with " << base << " base length and " << height << " height is " << area << endl;
    }
    
};
    
void fillDimension(string type);

int main(int argc, char* argv[]) {
    
    while (true) {
        
        int decision;
        string shape[3] = {"cir", "rect", "tri"};
        
        cout << "1) Circle\n";
        cout << "2) Rectangle\n";
        cout << "3) Triangle\n";
        cout << "0) Exit\n";
        cout << "Your choice: ";

        cin >> decision;
        
        if (decision >= 1 and decision <= 3) {
            fillDimension(shape[decision - 1]);
            cout << endl;
            continue;
        }
        
        cout << "The program has been terminated.\n";
        exit(0);
    }
}

void fillDimension(string type) {
    
    double temp1, temp2;
    
    if (type == "cir") {
        cout << "Enter the radius of a circle: ";
        cin >> temp1;
        Circle circle(temp1);
        PrintShape::printArea(circle);
    }
    else if (type == "rect") {
        cout << "Enter the width of a rectangle: ";
        cin >> temp1;
        cout << "Enter the height of a rectangle: ";
        cin >> temp2;
        Rectangle rectangle(temp1, temp2);
        PrintShape::printArea(rectangle);
    }
    else {
        cout << "Enter the base length of a triangle: ";
        cin >> temp1;
        cout << "Enter the height of a triangle: ";
        cin >> temp2;
        Triangle triangle(temp1, temp2);
        PrintShape::printArea(triangle);
    }
}
