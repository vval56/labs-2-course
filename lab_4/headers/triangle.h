#ifndef TRIANGLE_H 
#define TRIANGLE_H

#include <iostream>
#include "shapes.h"

class Triangle : public Shape {
public:
    explicit Triangle(const double * parametrs) : side1_(parametrs[0]), side2_(parametrs[1]) {}
    double square() const override;
    void parametrs() const override;
    std::string name() const override;
private:
    double side1_;
    double side2_;
    double square_;
    std::string name_ = "Треугольник";
};

#endif