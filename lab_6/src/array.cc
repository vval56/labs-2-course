#include "../include/array.h"
#include <iostream>
#include <stdexcept>

Array::Array() : size_(0), data_(nullptr) {}

Array::Array(const int* array, int size) : size_(size), data_(new int[size]) {
    for (int i = 0; i < size_; i++) {
        data_[i] = array[i];
    }
}

Array::Array(const Array& other) : size_(other.size_), data_(new int[other.size_]) {
    for (int i = 0; i < size_; i++) {
        data_[i] = other.data_[i];
    }
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] data_;
        
        size_ = other.size_;
        data_ = new int[size_];
        
        for (int i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

Array::~Array() {
    delete[] data_;
}

int Array::get_element(int index) const {
    if (index < 0 || index >= size_) {
        throw std::string("Индекс ") + std::to_string(index) + " выходит за границы массива";
    }
    return data_[index];
}

void Array::print() const {
    if (size_ == 0) {
        std::cout << "Массив пуст." << std::endl;
        return;
    }
    
    std::cout << "Массив [" << size_ << "]: ";
    for (int i = 0; i < size_; i++) {
        std::cout << data_[i];
        if (i < size_ - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}

void Array::add_element(int value) {
    auto temp_data = new int[size_ + 1];
    
    for (int i = 0; i < size_; i++) {
        temp_data[i] = data_[i];
    }
    
    temp_data[size_] = value;
    delete[] data_;
    data_ = temp_data;
    size_++;
}

void Array::delete_element(int index) {
    if (index < 0 || index >= size_) {
        throw std::string("Индекс ") + std::to_string(index) + " выходит за границы массива";
    }
    
    if (size_ == 1) {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
        return;
    }
    
    auto temp_data = new int[size_ - 1];
    
    for (int i = 0; i < index; i++) {
        temp_data[i] = data_[i];
    }
    
    for (int i = index; i < size_ - 1; i++) {
        temp_data[i] = data_[i + 1];
    }
    
    delete[] data_;
    data_ = temp_data;
    size_--;
}