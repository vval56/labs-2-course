#ifndef ARRAY_H
#define ARRAY_H

class Array {
private:
    int size_;
    int* data_;

public:
    Array();
    Array(const int* array, int size);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();
    int get_element(int index) const;
    void print() const;
    void add_element(int value);
    void delete_element(int index);
    int get_size() const { return size_; }
};

#endif