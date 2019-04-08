//
// Created by Leon Ngai on 2019-04-07.
//

#ifndef PROJECT_PART1_H
#define PROJECT_PART1_H

#include <iostream>
#include <math.h>
using namespace std;

class Point {
public:
    Point() = default;
    Point(double x, double y);

    void display();
    int counter();
    void incrementCount();

    void setX(double x);
    void setY(double y);

    double calculateDistance(Point p);
    static double calculateDistance(Point p1, Point p2) {
        double xDifference = p1.x - p2.x;
        double yDifference = p1.y - p2.y;

        return sqrt(pow(xDifference, 2) + pow(yDifference, 2));
    };

private:
    double x;
    double y;
    double id;

    static int count;
    static int randomId;

};
#endif //PROJECT_PART1_H
