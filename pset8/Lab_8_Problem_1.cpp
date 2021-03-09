/*
 
 ID: 63011283
 Name: Rachapoom Phanchotong
 Lab No: 8
 Question No: 1
 Date: March 9, 2021
 
 */

// TODO Tasks
// Adding copy constructors
// overload the assignment operator

#include <iostream>
using namespace std;

// MARK: - CircleClass

class Circle {
    
private:
    
    double radius;
    
public:
    
    // Constructor
    Circle(double r) {
        this->radius = r;
    }
    
    // Copy constructor
    Circle(const Circle &circle) {
        this->radius = circle.radius;
    }
    
    // Overload assignment operator
    Circle& operator = (Circle &circle) {
        this->radius = circle.getRadius();
        return circle;
    }
    
    double getArea() {
        return M_PI * pow(this->radius, 2);
    }
    
    double getRadius() {
        return this->radius;
    }
    
};


// MARK: - RectangleClass

class Rectangle {
    
private:
    
    double width;
    double height;
    
public:
    
    // Constructor
    Rectangle(double width, double height) {
        this->width = width;
        this->height = height;
    }
    
    // Copy constructor
    Rectangle(const Rectangle &rectangle) {
        this->width = rectangle.width;
        this->height = rectangle.height;
    }
    
    // Overload assignment operator
    Rectangle& operator = (Rectangle &rectangle) {
        this->width = rectangle.getWidth();
        this->height = rectangle.getHeight();
        return rectangle;
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

    
// MARK: - TriangleClass

class Triangle {

private:
    
    double base;
    double height;
    
public:
    
    // Constructor
    Triangle(double base, double height) {
        this->base = base;
        this->height = height;
    }
    
    // Copy constructor
    Triangle(const Triangle &triangle) {
        this->base = triangle.base;
        this->height = triangle.height;
    }
    
    // Overload assignment operator
    Triangle& operator = (Triangle &triangle) {
        this->base = triangle.getBase();
        this->height = triangle.getHeight();
        return triangle;
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

// MARK: - UtilityClass
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

// MARK: - MAIN
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
