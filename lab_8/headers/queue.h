#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"
#include <string>

template<typename t>
class Queue{
public:
    void push(const t value);
    void pop();
    t front() const;
    bool empty() const;
    void clear();
    
    class Iterator{
    private:
        Node<t> * current_;
    public:
        explicit Iterator(Node<t> * node) : current_(node) {}
        Iterator& operator++();
        t& operator*();
        bool operator!=(const Iterator & other) const;
    };

    Iterator begin();
    Iterator end();

    Queue() = default;
    ~Queue() { clear(); }

    Queue(const Queue<t>& other) {
        Node<t>* current = other.start_;
        while (current) {
            push(current->data_);
            current = current->next_;
        }
    }

    Queue<t>& operator=(const Queue<t>& other) {
        if (this != &other) {
            clear();
            Node<t>* current = other.start_;
            while (current) {
                push(current->data_);
                current = current->next_;
            }
        }
        return *this;
    }
private:
    Node<t> * start_ = nullptr;
    Node<t> * end_ = nullptr;
};

#endif