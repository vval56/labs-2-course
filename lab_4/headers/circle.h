#ifndef CIRCLE_H 
#define CIRCLE_H

#include <iostream>
#include "shapes.h"

class Circle : public Shape {
public:
    explicit Circle(const double * parametrs) : radius_(parametrs[0]) {}
    double square() const override;
    void parametrs() const override;
    std::string name() const override;
private:
    double radius_;
    double square_;
    std::string name_ = "Круг";
};

#endif