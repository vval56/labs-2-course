#ifndef ARRAY_EXCEPTION_H
#define ARRAY_EXCEPTION_H

#include <string>
#include <stdexcept>

class Array_exception : public std::exception {
private:
    std::string message_ = "Операция невозможна: массив пуст";
    
public:
    explicit Array_exception(int index) {
        message_ = "Индекс " + std::to_string(index) + " выходит за границы массива";
    }
    
    const char* what() const noexcept override {
        return message_.c_str();
    }
};

#endif