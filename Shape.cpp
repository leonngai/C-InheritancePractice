//
// Created by Leon Ngai on 2019-04-09.
//

#include "Shape.h"
#include <iostream>
using namespace std;

Shape::Shape(double x, double y, const char*inputName) : origin(x, y) {
    shapeName = new char[sizeof(inputName) + 1];
    strcpy(shapeName,inputName);
};

Shape::Shape(const Shape& source) {
    copy(source);
};

Shape &Shape::operator =(const Shape& source) {
    if (this != &source) {
        destroy();
        copy(source);
    }

    return *this;
};

void Shape::copy (const Shape &source) {
    origin = source.origin;
    shapeName = new char[sizeof(source.shapeName) + 1];
    strcpy(shapeName,source.shapeName);
}

Shape::~Shape() {
    destroy();
}

void Shape::destroy() {
    delete [] shapeName;
}

const char* Shape::getName() const { return shapeName; }
const Point& Shape::getOrigin() const { return origin; }
void Shape::display() {
    cout << "Shape Name: " << getName() << endl;
    origin.display();
}
void Shape::move(double dx, double dy) {
    double newX = origin.getX() + dx;
    double newY = origin.getY() + dy;

    origin.setX(newX);
    origin.setY(newY);
}

double Shape::distance(Shape& other) {
    return this->origin.calculateDistance(other.origin);
}
