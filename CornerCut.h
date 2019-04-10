//
// Created by Leon Ngai on 2019-04-10.
//

#ifndef ENSF_PROJECT_CORNERCUT_H
#define ENSF_PROJECT_CORNERCUT_H

#include "Rectangle.h"
#include "Circle.h"

class CornerCut: public Rectangle, public Circle{

public:
    CornerCut(double x, double y, double width, double length, double radius, const char *inputName);
    CornerCut(const CornerCut& source);
    CornerCut& operator =(const CornerCut& source);

    double area() override;
    double perimeter() override;
    void display() override;

};
#endif //ENSF_PROJECT_CORNERCUT_H
