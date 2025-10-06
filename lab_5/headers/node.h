#ifndef NODE_H
#define NODE_H

template<typename Type>
class Node {
public:
    Type data;
    Node<Type>* next = nullptr;
    Node<Type>* prev = nullptr;
    
    explicit Node(Type value) : data(value) {}
};

#endif