//
// Created by Leon Ngai on 2019-04-09.
//

#include "Point.h"
#include <iostream>
#include <cmath>
using namespace std;

int Point::randomId = 1000;

Point::Point(double x, double y) : x(x), y(y), id(++randomId) {}

Point& Point::operator =(const Point& source)
{
    if (this != &source) {
        x = source.x;
        y = source.y;
        id = source.id;
    }

    return *this;
}

void Point:: display() {
    cout << "X-Coordinate: " << x << endl;
    cout << "Y-Coordinate: " << y << endl;
}

int Point::counter() { return randomId - 1000; }
const double Point::getX() const { return this->x; }
const double Point::getY() const { return this->y; }
const int Point::getId() const { return this->id; }
void Point::setX(double x) { this->x = x; }
void Point::setY(double y) { this->y = y; }

double Point::calculateDistance(Point p) {
    double xDifference = this->x - p.x;
    double yDifference = this->y - p.y;

    return sqrt(pow(xDifference, 2) + pow(yDifference, 2));
}