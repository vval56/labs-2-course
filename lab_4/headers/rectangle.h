#ifndef RECTANGLE_H 
#define RECTANGLE_H

#include <iostream>
#include "shapes.h"

class Rectangle : public Shape {
public:
    explicit Rectangle(const double * parametrs) : side1_(parametrs[0]), side2_(parametrs[1]) {}
    double square() const override;
    void parametrs() const override;
    std::string name() const override;
private:
    double side1_;
    double side2_;
    double square_;
    std::string name_ = "Прямоугольник";
};

#endif