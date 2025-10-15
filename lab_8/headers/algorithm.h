#ifndef ALGORITHN_H
#define ALGORITHN_H

#include "queue.h"

class Algorithm{
public:
    static Queue::Iterator find(Queue::Iterator start, Queue::Iterator end, const int& value);
    static void sort(Queue queue);
};

#endif