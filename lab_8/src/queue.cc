#include "../headers/queue.h"
#include <iostream>

bool Queue::empty() const {
    return start_ == nullptr;
}

void Queue::push(const int value) {
    auto new_node = new Node(value);

    if (empty()) {
        start_ = end_ = new_node;
    } else {
        end_->next_ = new_node;
        end_ = new_node;
    }
}

void Queue::pop() {
    if (empty()) {
        throw std::string("Очередь пуста\n");
    }

    Node* temp = start_;
    start_ = start_->next_;
    delete temp;

    if (start_ == nullptr)
        end_ = nullptr;
}

int Queue::front() const {
    if (empty()) {
        throw std::string("Очередь пуста\n");
    }
    return start_->data_;
}

Queue::Iterator& Queue::Iterator::operator++() {
    if (current_) current_ = current_->next_;
    return *this;
}

int& Queue::Iterator::operator*() {
    if (!current_) throw std::string("Dereferencing end iterator");
    return current_->data_;
}

bool Queue::Iterator::operator!=(const Iterator& other) const {
    return current_ != other.current_;
}

Queue::Iterator Queue::begin() {
    return Iterator(start_);
}

Queue::Iterator Queue::end() {
    return Iterator(nullptr);
}
