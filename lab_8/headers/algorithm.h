#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "queue.h"

template<typename t>
class Algorithm {
public:
    static typename Queue<t>::Iterator find(Queue<t>::Iterator start, Queue<t>::Iterator end, const t& value);
    static void sort(Queue<t>& queue);
    
private:
    static void quickSort(t* arr, int low, int high); 
    static int partition(t* arr, int low, int high);
    static void swap(t& a, t& b);
};

#endif