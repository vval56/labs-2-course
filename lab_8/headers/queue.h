#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"
#include <string>

class Queue{
public:
    void push(const int value);
    void pop();
    int front() const;
    bool empty() const;

    class Iterator{
    private:
        Node * current_;
    public:
        explicit Iterator(Node * node) : current_(node) {}
        Iterator& operator++();
        int& operator*();
        bool operator!=(const Iterator & other) const;
    };

    Iterator begin();
    Iterator end();
private:
    Node * start_ = nullptr;
    Node * end_ = nullptr;
};

#endif