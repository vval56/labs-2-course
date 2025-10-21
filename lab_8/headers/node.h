#ifndef NODE_H
#define NODE_H

template<typename t>
class Node {
public:
    t data_;
    Node* next_ = nullptr;
    Node* prev_ = nullptr;
    
    explicit Node(t value) : data_(value) {}
};

template class Node<int>;
template class Node<double>;
template class Node<char>;

#endif