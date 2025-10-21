#include "../headers/queue.h"
#include <iostream>

template<typename T>
bool Queue<T>::empty() const {
    return start_ == nullptr;
}

template<typename T>
void Queue<T>::push(const T value) {
    auto new_node = new Node<T>(value);

    if (empty()) {
        start_ = end_ = new_node;
    } else {
        end_->next_ = new_node;
        end_ = new_node;
    }
}

template<typename T>
void Queue<T>::clear() {

    Node<T>* current = start_;
    int count = 0;
    while (current != nullptr) {
        Node<T>* next = current->next_;
        delete current;
        current = next;
        count++;
    }
    start_ = end_ = nullptr;
}

template<typename T>
void Queue<T>::pop() {
    if (empty()) {
        throw std::string("Очередь пуста\n");
    }

    Node<T>* temp = start_;
    start_ = start_->next_;
    
    if (start_ != nullptr) {
        start_->prev_ = nullptr;
    } else {
        end_ = nullptr;
    }
    
    delete temp;
}

template<typename T>
T Queue<T>::front() const {
    if (empty()) {
        throw std::string("Очередь пуста\n");
    }
    return start_->data_;
}

template<typename T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++() {
    if (current_) current_ = current_->next_;
    return *this;
}

template<typename T>
T& Queue<T>::Iterator::operator*() {
    if (!current_) throw std::string("Dereferencing end iterator");
    return current_->data_;
}

template<typename T>
bool Queue<T>::Iterator::operator!=(const Iterator& other) const {
    return current_ != other.current_;
}

template<typename T>
typename Queue<T>::Iterator Queue<T>::begin() {
    return Iterator(start_);
}

template<typename T>
typename Queue<T>::Iterator Queue<T>::end() {
    return Iterator(nullptr);
}

template class Queue<int>;
template class Queue<double>;
template class Queue<char>;
