//
// Created by Leon Ngai on 2019-04-09.
//

#include "Square.h"
#include <iostream>
using namespace std;

Square::Square(double x, double y, double side_a, const char *inputName) : Shape(x, y, inputName), side_a(side_a){}
Square::Square(const Square &source) : Shape(source.origin.getX(), source.origin.getY(), source.shapeName), side_a(source.side_a){}
Square &Square::operator=(const Square &source) {
    if (this != &source) {
        destroy();
        copy(source);
        side_a = source.side_a;
    }

    return *this;
}

double Square::area() { return side_a * side_a; }
double Square::perimeter() { return side_a * 4; }
void Square::display() {
    cout << "Square Name: " << shapeName << endl;
    origin.display();
}

double Square::getSideA() const { return side_a; }
void Square::setSideA(double side) { side_a = side; }

