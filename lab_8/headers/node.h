#ifndef NODE_H
#define NODE_H

class Node {
public:
    int data_;
    Node* next_ = nullptr;
    Node* prev_ = nullptr;
    
    explicit Node(int value) : data_(value) {}
};

#endif