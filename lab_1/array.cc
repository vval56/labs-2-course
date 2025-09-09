#include "array.h"

#include <ctime>

Array::Array(int size) : size_(size), data(new int[size_]){}

Array::Array(int size, int* values): size_(size){   
    data = new int[size_];
    for(int i = 0; i < size_; i++)
        data[i] = values[i];
}

Array::Array(int size, bool is_random) : size_(size) {
    data = new int[size_];
    if(is_random == true) {
    srand(time(0));
    for(int i = 0; i < size_; i++) {
        data[i] = rand() % 100;
    }
    }
}

Array::~Array() {
    delete[] data;
}

int Array::Size()  {
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