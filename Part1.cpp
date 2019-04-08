//
// Created by Leon Ngai on 2019-04-07.
//

#include "Part1.h"
#include <iostream>
#include <math.h>
using namespace std;

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
    id = randomId++;
    incrementCount();
}

void Point::display() {
    cout << "X-Coordinate: " << x << endl;
    cout << "Y-Coordinate: " << y << endl;
}

int Point::counter() {
    return count;
}

void Point::incrementCount() {
    count++;
}

void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

double Point::calculateDistance(Point p) {
    double xDifference = this->x - p.x;
    double yDifference = this->y - p.y;

    return sqrt(pow(xDifference, 2) + pow(yDifference, 2));
}

int Point::count = 0;
int Point::randomId = 1001;

int main() {
    Point p(10,20);
    p.display();
//    cout << p.counter();

    Point p2(-10,-20);
    cout << p.calculateDistance(p2) << endl;

    cout << Point::calculateDistance(p,p2);


}