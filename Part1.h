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
    Point& operator =(const Point& source);

    void display();
    int counter();
    void incrementCount();

    double getX() const;
    double getY() const;
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

class Shape {
public:
    Shape() = default;
    Shape(double x, double y, const char*inputName);
    ~Shape();

    const char* getName() const;
    void display();
    void move(double dx, double dy);
    const Point* getOrigin();

    double distance(Shape& other);
    static double distance(Shape& the_shape, Shape& other) {
        return Point::calculateDistance(the_shape.origin, other.origin);
    }

protected:
    Point origin;
    const char* shapeName;

};

class Square: public Shape{
private:
    double side_a;
public:
    Square() = default;
    Square(double x, double y, double side_a, const char *inputName);

    double area();
    double perimeter();
    void display();

    double getSideA() const;
    void setSideA(double side_a);

};

class Rectangle: public Square{
private:
    double side_b;
public:
    Rectangle(double x, double y, double side_a, double side_b, const char *inputName);
    Rectangle(const Rectangle& source);
    Rectangle& operator =(const Rectangle& source);

    double area();
    double perimeter();
    void display();
    void copy(const Rectangle& source);

    double getSideB();
    void setSideB(double side_b);

};

class Circle: public Shape{
private:
    double radius;
public:
    Circle(double x, double y, double radius, const char *inputName);

    double area();
    double perimeter();
    void display();

    double get();
    void set(double radius);

};

class GraphicsWorld {
public:
    void run();
};

#endif //PROJECT_PART1_H
