//
// Created by Leon Ngai on 2019-04-10.
//

#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(double x, double y, double side_a, double side_b, const char *inputName) : Square(x, y, side_a, inputName), Shape(x, y, inputName), side_b(side_b){}
Rectangle::Rectangle(const Rectangle& source) : Square(source.origin.getX(), source.origin.getY(), source.getSideA(), source.shapeName), Shape(source.origin.getX(), source.origin.getY(), source.shapeName), side_b(source.side_b) {}
Rectangle& Rectangle::operator =(const Rectangle& source) {
    if (this != &source) {
        destroy();
        copy(source);
        side_a = source.getSideA();
        side_b = source.getSideB();
    }
    return *this;
};

double Rectangle::area() {
    return Square::getSideA() * side_b;
}

double Rectangle::perimeter() {
    return side_b * 2 + Square::getSideA() * 2;
}

void Rectangle::setSideB(double side) { this->side_b = side; }
double Rectangle::getSideB() const { return side_b; }

void Rectangle::display() {
    cout << "Rectangle Name: " << getName() << endl;
    origin.display();
}