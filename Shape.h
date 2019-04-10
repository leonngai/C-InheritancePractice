//
// Created by Leon Ngai on 2019-04-09.
//

#ifndef ENSF_PROJECT_SHAPE_H
#define ENSF_PROJECT_SHAPE_H

#include "Point.h"

class Shape {
public:
    Shape(double x, double y, const char* inputName);
    Shape(const Shape& source);
    Shape& operator =(const Shape& source);
    virtual ~Shape();
    void destroy();
    void copy(const Shape &source);

    const char* getName() const;
    const Point& getOrigin() const;
    virtual void display();
    void move(double dx, double dy);


    double distance(Shape& other);
    static double distance(Shape& the_shape, Shape& other) {
        return Point::calculateDistance(the_shape.origin, other.origin);
    }

    virtual double area() = 0;
    virtual double perimeter() = 0;

protected:
    Point origin;
    char* shapeName;

};

#endif //ENSF_PROJECT_SHAPE_H
