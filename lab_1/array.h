#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using namespace std;

class Array {
    public:
        explicit Array(int size);
       

        Array(int size, int* values);   

        Array(int size, bool is_random);

        virtual ~Array();

        int Size();
        
        int Get(int index) const;
        
        const int* GetData() const; 
   
    private:
        int* data;
        int size_;
};

#endif