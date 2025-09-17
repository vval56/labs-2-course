#include "../headers/array.h"

#include <random>

using namespace std;

Array::Array() : data(new int[1]), size_(1){}

Array::Array(int size) : data(new int[size]), size_(size){}

Array::Array(int size, const int* values): size_(size){   
    data = new int[size_];
    for(int i = 0; i < size_; i++)
        data[i] = values[i];
}

Array::Array(int size, bool is_random) : size_(size) {
    data = new int[size_];

    if(is_random) {
        static random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution dist(0, 100);

        for(int i = 0; i < size_; i++) {
            data[i] = dist(gen);
        }
    }
}

Array::Array(const Array& other) : data(new int[other.size_]), size_(other.size_) {
    for(int i = 0; i < size_; i++) {
        data[i] = other.data[i];
    }
}

Array& Array::operator=(const Array& other) {
    if (this != &other) { 
        delete[] data; 
        
        size_ = other.size_;
        data = new int[size_];
        for(int i = 0; i < size_; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

Array& Array::operator=(Array&& other) noexcept {
    if (this != &other) {
        delete[] data; 
        
        size_ = other.size_;
        data = other.data;
        
        other.size_ = 0;
        other.data = nullptr;
    }
    return *this;
}

Array::Array(Array&& other) noexcept : data(other.data), size_(other.size_) {
    other.size_ = 0;
    other.data = nullptr;
}

Array::~Array() {
    delete[] data;
}

int Array::Size() const {
    return size_;
}

int Array::Get(int index) const {
    if (index < 0 || index >= size_) {
        throw out_of_range("Index out of range");
    }
    return data[index];
}

const int* Array::GetData() const {
    return data;
}