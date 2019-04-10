//
// Created by Leon Ngai on 2019-04-09.
//

#ifndef ENSF_PROJECT_SQUARE_H
#define ENSF_PROJECT_SQUARE_H

#include "Shape.h"

class Square: virtual public Shape{
protected:
    double side_a;
public:
    Square(double x, double y, double side_a, const char *inputName);
    Square(const Square& source);
    Square& operator =(const Square& source);
//    virtual ~Square();

    double area() override;
    double perimeter() override;
    void display() override;

    double getSideA() const;
    void setSideA(double side_a);

};
#endif //ENSF_PROJECT_SQUARE_H
