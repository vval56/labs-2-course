#ifndef QUEUES_H
#define QUEUES_H

#include "sample_queue.h"
#include <iostream>
#include <type_traits>

class Queue_array {
private:
    Queue<int>** int_queues_;
    Queue<double>** double_queues_;
    Queue<char>** char_queues_;
    Queue<std::string>** string_queues_;
    
    int count_int_ = 0;
    int count_double_ = 0; 
    int count_char_ = 0; 
    int count_string_ = 0;

    void copy_int_queues(const Queue_array& other, Queue<int>**& new_int) const;
    void copy_double_queues(const Queue_array& other, Queue<double>**& new_double) const;
    void copy_char_queues(const Queue_array& other, Queue<char>**& new_char) const;
    void copy_string_queues(const Queue_array& other, Queue<std::string>**& new_string) const;

    void clear_int_queues();
    void clear_double_queues();
    void clear_char_queues();
    void clear_string_queues();
    void assign_from_copy(Queue<int>** new_int, Queue<double>** new_double, 
                         Queue<char>** new_char, Queue<std::string>** new_string,
                         const Queue_array& other);
public:
    Queue_array();
    ~Queue_array();
    Queue_array(const Queue_array& other);
    Queue_array& operator=(const Queue_array& other);
    Queue_array(Queue_array&& other) noexcept;
    Queue_array& operator=(Queue_array&& other) noexcept;

    template<typename Type>
    int create_queue(Queue<Type>* queue);
    
    template<typename Type>
    Queue<Type>* get_queue(int index);
    
    template<typename Type>
    bool enqueue(int index, const Type& value);
    
    template<typename Type>
    bool dequeue(int index);
    
    void print_all() const;
};

#endif