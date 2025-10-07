#ifndef SAMPLE_QUEUE_H
#define SAMPLE_QUEUE_H

#include <iostream>
#include "node.h"

template<typename Type>
class Queue{
public:
    Queue() = default;
    Queue(const Queue& other);             
    Queue(Queue&& other) noexcept;              
    Queue& operator=(const Queue& other);     
    Queue& operator=(Queue&& other) noexcept;
    virtual ~Queue();       
    
    bool operator!() const;
    void enqueue(Type value);
    void dequeue();
    void print();
    int size() const;
    Type start();
    Type end();
    Type pop();
    
private:
    Node<Type>* start_ = nullptr;
    Node<Type>* end_ = nullptr;
    int size_ = 0;
};

#endif