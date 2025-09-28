#ifndef SHAPES_H
#define SHAPES_H

#include <iostream>

class Shape{
    public:
        Shape();
        virtual ~Shape();
        Shape(const Shape& other);
        Shape& operator=(Shape&& other) noexcept;
        Shape(Shape&& other) noexcept;

        virtual bool intersect_with(const Shape* other) const = 0;
        virtual bool intersect_with(const Shape* other) const = 0;
        virtual bool intersect_with(const Shape* other) const = 0;
        virtual bool intersect_with(const Shape* other) const = 0;
    private:
        double square_;
};

class Circle : public Shape {

};

#endif