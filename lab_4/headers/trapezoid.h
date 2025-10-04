#ifndef TRAPEZOID_H 
#define TRAPEZOID_H

#include <iostream>
#include "shapes.h"

class Trapezoid : public Shape {
public:
    explicit Trapezoid(const double * parametrs) : side1_(parametrs[0]), side2_(parametrs[1]), height_(parametrs[2]) {}
    double Square() const override;
    void Parametrs() const override;
    std::string Name() const override;
private:
    double side1_;
    double side2_;
    double height_;
    double square_;
    std::string name = "Трапеция";
};

#endif