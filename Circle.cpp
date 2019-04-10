//
// Created by Leon Ngai on 2019-04-10.
//

#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle(double x, double y, double radius, const char *inputName) : Shape(x, y, inputName), radius(radius) {};
Circle::Circle(const Circle& source) : Shape(source.origin.getX(), source.origin.getY(), source.shapeName), radius(source.radius) {};
Circle &Circle::operator=(const Circle &source) {
    if(this != &source) {
        destroy();
        copy(source);
        radius = source.radius;
    }

    return *this;
};

double Circle::area() { return radius * radius * M_PI; };
double Circle::perimeter() { return 2 * radius * M_PI; };
void Circle::display() {
    cout << "Circle Name: " << getName() << endl;
    origin.display();
};

double Circle::getRadius() { return radius; };

void Circle::setRadius(double radius) { this->radius = radius; };