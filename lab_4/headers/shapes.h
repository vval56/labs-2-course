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
    virtual double Square() const = 0;
    virtual std::string Name() const = 0;
    virtual void Parametrs() const = 0;
};

#endif