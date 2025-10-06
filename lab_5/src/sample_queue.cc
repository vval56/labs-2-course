#include "../headers/sample_queue.h"
#include <iostream>
#include <vector>

template<typename Type>
bool Queue<Type>::operator!() const {
    return size_ == 0;
}

template<typename Type>
void Queue<Type>::enqueue(Type value) {
    auto new_node = new Node<Type>(value);

    if (!start_) {
        start_ = end_ = new_node;
    } else {
        end_->next = new_node;
        new_node->prev = end_;
        end_ = new_node;
    }

    size_++;
}

template<typename Type>
void Queue<Type>::dequeue() {
    if (size_ == 0 || !start_) {
        std::cout << "Нечего удалять, очередь пуста\n";
        return;
    }

    Node<Type>* temp = start_;

    if (start_ == end_) {
        start_ = end_ = nullptr;
        std::cout << "Теперь очередь пуста\n";
    } else {
        start_ = start_->next;
        start_->prev = nullptr;
    }

    delete temp;
    size_--;
}

template<typename Type>
Type Queue<Type>::pop() {
    if (!start_) {
        std::cout << "Очередь пуста\n";
        return Type{}; 
    }
    Type value = start_->data;
    dequeue(); 
    return value;
}

template<typename Type>
void Queue<Type>::print() {
    if (!start_) {
        std::cout << "Очередь пуста.\n";
        return;
    }

    Node<Type>* curr = start_;
    while (curr) {
        std::cout << curr->data;
        if (curr->next) std::cout << " -> ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

template<typename Type>
Type Queue<Type>::start() {
    if (!start_) {
        std::cout << "Очередь пуста\n";
        return Type{}; 
    }
    return start_->data;
}

template<typename Type>
Type Queue<Type>::end() {
    if (!end_) {
        std::cout << "Очередь пуста\n";
        return Type{}; 
    }
    return end_->data;
}

template<typename Type>
int Queue<Type>::size() const{
    return size_;
}

template<typename Type>
Queue<Type>::Queue(const Queue& other) {
    Node<Type>* current = other.start_;
    while (current != nullptr) {
        this->enqueue(current->data);
        current = current->next;
    }
}

template<typename Type>
std::vector<Type> Queue<Type>::toVector() const {
    std::vector<Type> result;
    Node<Type>* current = start_;
    while (current != nullptr) {
        result.push_back(current->data);
        current = current->next;
    }
    return result;
}

template<typename Type>
Queue<Type>::Queue(Queue&& other) noexcept 
    : start_(other.start_), end_(other.end_), size_(other.size_) {
    other.start_ = nullptr;
    other.end_ = nullptr;
    other.size_ = 0;
}

template<typename Type>
Queue<Type>& Queue<Type>::operator=(const Queue& other) {
    if (this != &other) {
        while (start_) {
            dequeue();
        }
    
        Node<Type>* current = other.start_;
        while (current != nullptr) {
            this->enqueue(current->data);
            current = current->next;
        }
    }
    return *this;
}

template<typename Type>
Queue<Type>& Queue<Type>::operator=(Queue&& other) noexcept {
    if (this != &other) {
        while (start_) {
            dequeue();
        }
        
        start_ = other.start_;
        end_ = other.end_;
        size_ = other.size_;
    
        other.start_ = nullptr;
        other.end_ = nullptr;
        other.size_ = 0;
    }
    return *this;
}

template<typename Type>
Queue<Type>::~Queue() {
    while (start_) {
        dequeue();
    }
}


template class Queue<int>;
template class Queue<double>;
template class Queue<char>;
template class Queue<std::string>;