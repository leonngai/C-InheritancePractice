//
// Created by Leon Ngai on 2019-04-07.
//

#include "Part1.h"
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int Point::count = 0;
int Point::randomId = 1001;

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
    id = randomId++;
    incrementCount();
}

Point& Point::operator =(const Point& source)
{
    this->x = source.x;
    this->y = source.y;

    return *this;
}

void Point:: display() {
    cout << "X-Coordinate: " << x << endl;
    cout << "Y-Coordinate: " << y << endl;
}

int Point::counter() { return count; }
void Point::incrementCount() { count++; }

double Point::getX() const { return this->x; }
double Point::getY() const { return this->y; }
void Point::setX(double x) { this->x = x; }
void Point::setY(double y) { this->y = y; }

double Point::calculateDistance(Point p) {
    double xDifference = this->x - p.x;
    double yDifference = this->y - p.y;

    return sqrt(pow(xDifference, 2) + pow(yDifference, 2));
}

Shape::Shape(double x, double y, const char*inputName) {
    Point tempPoint(x, y);
    origin = tempPoint;

    int count = 0;
    const char *cursor = inputName;
    while (*cursor != '\0') {
        cursor += 1;
        count += 1;
    }

    char* temp = new char[count + 1];
    for ( int i = 0; i < count + 1; i++) {
        temp[i] = inputName[i];
    }

    shapeName = temp;
};

Shape::~Shape() {
    delete [] shapeName;
}

const char* Shape::getName() const { return shapeName; }
const Point* Shape::getOrigin() { return &origin; }

void Shape::display() {
    cout << "Shape Name: " << getName() << endl;
    origin.display();
}

double Shape::distance(Shape& other) {
    return this->origin.calculateDistance(other.origin);
}

void Shape::move(double dx, double dy) {
    double newX = origin.getX() + dx;
    double newY = origin.getY() + dy;

    origin.setX(newX);
    origin.setY(newY);
}

Square::Square(double x, double y, double side_a, const char *inputName) : Shape(x, y, inputName) {
    this->side_a = side_a;
}

double Square::area() {
    return side_a * side_a;
}

double Square::perimeter() {
    return side_a * 4;
}

double Square::getSideA() const { return side_a; }
void Square::setSideA(double side) { this->side_a = side; }

void Square::display() {
    cout << "Square Name: " << getName() << endl;
    origin.display();
}

Rectangle::Rectangle(double x, double y, double side_a, double side_b, const char *inputName) : Square(x, y, side_a, inputName){
    this->side_b = side_b;
}

Rectangle::Rectangle(const Rectangle& source) {
    copy(source);
}

Rectangle& Rectangle::operator =(const Rectangle& source) {
    copy(source);
    return *this;
};

void Rectangle::copy(const Rectangle& source) {
    Point tempPoint(source.origin.getX(), source.origin.getY());
    origin = tempPoint;

    int count = 0;
    const char* name = source.getName();
    const char* cursor = name;
    while (*cursor != '\0') {
        cursor += 1;
        count += 1;
    }

    char* temp = new char[count + 1];
    for ( int i = 0; i < count + 1; i++) {
        temp[i] = name[i];
    }

    shapeName = temp;
    setSideA(source.getSideA());
    setSideB(source.side_b);
}

double Rectangle::area() {
    return Square::getSideA() * side_b;
}

double Rectangle::perimeter() {
    return side_b * 2 + Square::getSideA() * 2;
}

void Rectangle::setSideB(double side) { this->side_b = side; }
double Rectangle::getSideB() { return side_b; }

void Rectangle::display() {
    cout << "Rectangle Name: " << getName() << endl;
    origin.display();
}

Circle::Circle(double x, double y, double radius, const char *inputName) : Shape(x, y, inputName) {
    this->radius = radius;
};

double Circle::area() {
    return radius * radius * M_PI;
};

double Circle::perimeter() {
    return 2 * radius * M_PI;
};

void Circle::display() {
    cout << "Circle Name: " << getName() << endl;
    origin.display();
};

double Circle::get() {
    return radius;
};

void Circle::set(double radius) {
    this->radius = radius;
};

CornerCut::CornerCut(double x, double y, double width, double length, double radius, const char *inputName) : Circle(x, y, radius, inputName), Rectangle(x, y, width, length, inputName){
    if (radius > width || radius > length) {
        cout << "Error! The radius is greater than the sides of the rectangle which is not allowed.\nProgram is quitting now." << endl;
        std::_Exit(EXIT_FAILURE);
    }
}

double CornerCut::area() {
// area can be found via total rectangle area - (1/4) * circle area
    double area = Rectangle::area();
    area -= (0.25 * Circle::area());
    return area;
}

double CornerCut::perimeter() {
// perimeter can be found via total rectangle perimeter - (2 * radius) + (1/4) * circle perimeter
    double perimeter = Rectangle::perimeter();
    perimeter -= (2 * Circle::get());
    perimeter += (0.25 * Circle::perimeter());
    return perimeter;
}
void CornerCut::display(){
    cout << "CornerCut Name: " << Circle::getName() << endl;
    Circle::origin.display();
    cout << "Width: " << Rectangle::getSideA() << endl;
    cout << "Length: " << Rectangle::getSideB() << endl;
    cout << "Radius of the cut: " << Circle::get() << endl;

}

const char* CornerCut::getName() const { return Circle::getName(); }
double CornerCut::distance(Shape& other) { return Circle::distance(other); }


void GraphicsWorld::run() {
    // Part 1
    cout << "\nThis program has been written by: Leon Ngai." ;
    cout << "\nTesting Functions in class Point:" <<endl;
    Point m (6, 8);
    Point n (6,8);

    n.setX(9);
    m.display();
    n.display();

    cout << "\nThe distance between two points m and n is: " << m.calculateDistance(n);
    cout << "\nThe distance between two points m and n using static method is: " << Point::calculateDistance(m, n);

    cout << "\nTesting Functions in class Square:" <<endl;
    Square s(5, 7, 12, "SQUARE - S");
    s.display();
    cout << "the area of " << s.getName() <<" is: "<< s.area() << "\n";
    cout << "the perimeter of " << s.getName() <<" is: " << s.perimeter() << "\n";
    cout << "\nTesting Functions in class Rectangle:" <<endl;
    Rectangle a(5, 7, 12, 15, "RECTANGLE A");
    a.display();
    Rectangle b(16 , 7, 8, 9, "RECTANGLE B");
    b.display();
    cout << "the area of " << a.getName() <<" is: "<< a.area() << "\n";
    cout << "the perimeter of " << a.getName() <<" is: "<< a.perimeter() << "\n";
    double d = a.distance(b);
    cout << "\nThe distance between two rectangles is: " <<d;
    cout << "\nTesting copy constructor in class Rectangle:" <<endl;
    Rectangle rec1 = a;
    rec1.display();
    cout << "\nTesting assignment operator in class Rectangle:" <<endl;
    Rectangle rec2 (3, 4, 11, 7, "RECTANGLE rec2");
    rec2.display();
    rec2 = a;
    rec2.display();
    cout << "\nTesting Functions in class Circle:" <<endl;
    Circle c (3, 5, 9, "CIRCLE C");
    c.display();
    cout << "the area of " << c.getName() <<" is: "<< c.area() << endl;
    cout << "the perimeter of " << c.getName() << " is: "<< c.perimeter() << endl;
    d = a.distance(c);
    cout << "\nThe distance between rectangle a and circle c is: " <<d << endl;

//Part 2
    CornerCut rc (6, 5, 10, 12, 9, "CornerCut rc");
    rc.display();
    cout << "the area of " << rc.getName() <<" is: "<< rc.area() << endl;
    cout << "the perimeter of " << rc.getName() << " is: "<< rc.perimeter() << endl;
    d = rc.distance(c);
    cout << "\nThe distance between rc and c is: " <<d << endl;
// Using array of Shape pointers:
    Shape* sh[4];
    sh[0] = &s;
    sh[1] = &a;
    sh [2] = &c;
    sh [3] = &rc;
    sh [0]->display();
    cout << "\nthe area of "<< sh[0]->getName() << " is: "<< sh[0] ->area();
    cout << "\nthe perimeter of " << sh[0]->getName () << " is: "<< sh[0]->perimeter() << endl;
    sh [1]->display();
    cout << "\nthe area of "<< sh[1]->getName() << " is: "<< sh[1] ->area();
    cout << "\nthe perimeter of " << sh[1]->getName () << " is: "<< sh[1]->perimeter() << endl;
    sh [2]->display();
    cout << "\nthe area of "<< sh[2]->getName() << " is: "<< sh[2] ->area();
    cout << "\nthe circumference of " << sh[2]->getName ()<< " is: "<< sh[2]->perimeter() << endl;
    sh [3]->display();
//    cout << "\nthe area of "<< sh[3]->getName() << "is: "<< sh[3] ->area();
//    cout << "\nthe perimeter of " << sh[3]->getName () << " is: "<< sh[3]->perimeter();
//    cout << "\nTesting copy constructor in class CornerCut:" <<endl;
//    CornerCut cc = rc;
//    cc.display();
//    cout << "\nTesting assignment operator in class CornerCut:" <<endl;
//    CornerCut cc2(2, 5, 100, 12, 9, "CornerCut cc2");
//    cc2.display();
//    cc2 = cc;
//    cc2.display();

}

int main() {
    GraphicsWorld g;
    g.run();
}
