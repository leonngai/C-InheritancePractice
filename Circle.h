//
// Created by Leon Ngai on 2019-04-10.
//

#ifndef ENSF_PROJECT_CIRCLE_H
#define ENSF_PROJECT_CIRCLE_H

#include "Shape.h"

class Circle: virtual public Shape{
protected:
    double radius;
public:
    Circle(double x, double y, double radius, const char *inputName);
    Circle(const Circle& source);
    Circle& operator =(const Circle& source);

    double area() override;
    double perimeter() override;
    void display() override;

    double getRadius();
    void setRadius(double radius);
};

#endif //ENSF_PROJECT_CIRCLE_H
