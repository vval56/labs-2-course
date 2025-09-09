#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array {
    public:
        explicit Array(int size);
       

        Array(int size, const int* values);   

        Array(int size, bool is_random);

        virtual ~Array();

        Array(const Array& other);

        Array& operator=(const Array& other);

        Array(Array&& other) noexcept;

        Array& operator=(Array&& other) noexcept;

        const int Size();
        
        int Get(int index) const;
        
        const int* GetData() const; 
   
    private:
        int* data;
        int size_;
};

#endif