//
// Created by Leon Ngai on 2019-04-10.
//

#ifndef ENSF_PROJECT_RECTANGLE_H
#define ENSF_PROJECT_RECTANGLE_H

#include "Square.h"

class Rectangle: virtual public Square{
protected:
    double side_b;
public:
    Rectangle(double x, double y, double side_a, double side_b, const char *inputName);
    Rectangle(const Rectangle& source);
    Rectangle& operator =(const Rectangle& source);

    double area() override;
    double perimeter() override;
    void display() override;

    double getSideB() const;
    void setSideB(double side_b);
};
#endif //ENSF_PROJECT_RECTANGLE_H
