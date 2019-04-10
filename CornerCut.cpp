//
// Created by Leon Ngai on 2019-04-10.
//

#include "CornerCut.h"
#include <iostream>
using namespace std;

CornerCut::CornerCut(double x, double y, double width, double length, double radius, const char *inputName) :
Circle(x, y, radius, inputName), Rectangle(x, y, width, length, inputName), Shape(x, y, inputName),
Square(x, y, width, inputName){
    if (radius > width || radius > length) {
        cout << "Error! The radius is greater than the sides of the rectangle which is not allowed.\nProgram is quitting now." << endl;
        std::_Exit(EXIT_FAILURE);
    }
}
CornerCut::CornerCut(const CornerCut& source) : Circle(source.origin.getX(), source.origin.getY(), source.radius, source.shapeName),
Rectangle(source.origin.getX(), source.origin.getY(), source.side_a, source.side_b, source.shapeName), Shape(source.origin.getX(), source.origin.getY(), source.shapeName),
        Square(source.origin.getX(), source.origin.getY(), source.side_a, source.shapeName) {
    if (source.radius > source.side_a || source.radius > source.side_b) {
        cout << "Error! The radius is greater than the sides of the rectangle which is not allowed.\nProgram is quitting now." << endl;
        std::_Exit(EXIT_FAILURE);
    }
};

CornerCut &CornerCut::operator=(const CornerCut &source) {
    if (this != &source) {
        destroy();
        copy(source);
        side_a = source.side_a;
        side_b = source.side_b;
        radius = source.radius;
    }
    return *this;
}

double CornerCut::area() {
// area can be found via total rectangle area - (1/4) * circle area
    double area = Rectangle::area();
    area -= (0.25 * Circle::area());
    return area;
}

double CornerCut::perimeter() {
// perimeter can be found via total rectangle perimeter - (2 * radius) + (1/4) * circle perimeter
    double perimeter = Rectangle::perimeter();
    perimeter -= (2 * getRadius());
    perimeter += (0.25 * Circle::perimeter());
    return perimeter;
}
void CornerCut::display(){
    cout << "CornerCut Name: " << shapeName << endl;
    origin.display();
    cout << "Width: " << getSideA() << endl;
    cout << "Length: " << getSideB() << endl;
    cout << "Radius of the cut: " << getRadius() << endl;

}

