#ifndef SHAPES_H
#define SHAPES_H

#include <iostream>

class Circle;
class Triangle;
class Rectangle;
class Trapezoid;

class Shape {
public:
    virtual ~Shape() = default;
    virtual double square() const = 0;
    virtual std::string name() const = 0;
    virtual void parametrs() const = 0;
};

#endif