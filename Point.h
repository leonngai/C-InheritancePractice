//
// Created by Leon Ngai on 2019-04-09.
//

#ifndef ENSF_PROJECT_POINT_H
#define ENSF_PROJECT_POINT_H

#include <math.h>

class Point {
public:
    Point() = default;
    Point(double x, double y);
    Point& operator =(const Point& source);

    void display();
    int counter();

    const double getX() const;
    const double getY() const;
    const int getId() const;
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
    int id;

    static int randomId;

};
#endif //ENSF_PROJECT_POINT_H
