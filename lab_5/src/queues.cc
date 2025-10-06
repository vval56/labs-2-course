#include "../headers/queues.h"
#include <iostream>
using namespace std;

Queue_array::Queue_array() : 
    int_queues_(nullptr), double_queues_(nullptr), char_queues_(nullptr), string_queues_(nullptr) {}

Queue_array::~Queue_array() {
    for (int i = 0; i < count_int_; i++) delete int_queues_[i];
    for (int i = 0; i < count_double_; i++) delete double_queues_[i];
    for (int i = 0; i < count_char_; i++) delete char_queues_[i];
    for (int i = 0; i < count_string_; i++) delete string_queues_[i];

    delete[] int_queues_;
    delete[] double_queues_;
    delete[] char_queues_;
    delete[] string_queues_;
}

template<typename Type>
int Queue_array::create_queue(Queue<Type>* queue) {
    if constexpr (is_same_v<Type, int>) {
        auto new_arr = new Queue<int>*[count_int_ + 1];
        for (int i = 0; i < count_int_; i++)
            new_arr[i] = int_queues_[i];
        new_arr[count_int_] = queue; 
        delete[] int_queues_;
        int_queues_ = new_arr;
        return count_int_++;
    }
    else if constexpr (is_same_v<Type, double>) {
        auto new_arr = new Queue<double>*[count_double_ + 1];
        for (int i = 0; i < count_double_; i++)
            new_arr[i] = double_queues_[i];
        new_arr[count_double_] = queue;
        delete[] double_queues_;
        double_queues_ = new_arr;
        return count_double_++;
    }
    else if constexpr (is_same_v<Type, char>) {
        auto new_arr = new Queue<char>*[count_char_ + 1];
        for (int i = 0; i < count_char_; i++)
            new_arr[i] = char_queues_[i];
        new_arr[count_char_] = queue;
        delete[] char_queues_;
        char_queues_ = new_arr;
        return count_char_++;
    }
    else if constexpr (is_same_v<Type, string>) {
        auto new_arr = new Queue<string>*[count_string_ + 1];
        for (int i = 0; i < count_string_; i++)
            new_arr[i] = string_queues_[i];
        new_arr[count_string_] = queue;
        delete[] string_queues_;
        string_queues_ = new_arr;
        return count_string_++;
    }
    return -1;
}

template<typename Type>
Queue<Type>* Queue_array::get_queue(int index) {
    if constexpr (is_same_v<Type, int>) {
        if (index >= 0 && index < count_int_) return int_queues_[index];
    }
    else if constexpr (is_same_v<Type, double>) {
        if (index >= 0 && index < count_double_) return double_queues_[index];
    }
    else if constexpr (is_same_v<Type, char>) {
        if (index >= 0 && index < count_char_) return char_queues_[index];
    }
    else if constexpr (is_same_v<Type, string>) {
        if (index >= 0 && index < count_string_) return string_queues_[index];
    }
    return nullptr;
}

template<typename Type>
bool Queue_array::enqueue(int index, const Type& value) {
    if (Queue<Type>* q = get_queue<Type>(index)){ q->enqueue(value); return true; }
    else {cout << "Очередь не найдена!" << endl; return false;}
}

template<typename Type>
bool Queue_array::dequeue(int index) {
    Queue<Type>* q = get_queue<Type>(index);
    if (q && q->size() > 0) {
        q->dequeue();
        return true;
    }
    return false;
}

void Queue_array::print_all() const {
    cout << "\n=== INT QUEUES ===" << endl;
    for (int i = 0; i < count_int_; i++) {
        cout << i << ": "; int_queues_[i]->print();
    }
    cout << "\n=== DOUBLE QUEUES ===" << endl;
    for (int i = 0; i < count_double_; i++) {
        cout << i << ": "; double_queues_[i]->print();
    }
    cout << "\n=== CHAR QUEUES ===" << endl;
    for (int i = 0; i < count_char_; i++) {
        cout << i << ": "; char_queues_[i]->print();
    }
    cout << "\n=== STRING QUEUES ===" << endl;
    for (int i = 0; i < count_string_; i++) {
        cout << i << ": "; string_queues_[i]->print();
    }
}

Queue_array::Queue_array(const Queue_array& other) :
        count_int_(other.count_int_),
        count_double_(other.count_double_),
        count_char_(other.count_char_),
        count_string_(other.count_string_)
    {
        if (other.count_int_ > 0) {
            int_queues_ = new Queue<int>*[other.count_int_];
            for (int i = 0; i < other.count_int_; ++i) {
                int_queues_[i] = new Queue<int>(*other.int_queues_[i]);
            }
        } else {
            int_queues_ = nullptr;
        }
        
        if (other.count_double_ > 0) {
            double_queues_ = new Queue<double>*[other.count_double_];
            for (int i = 0; i < other.count_double_; ++i) {
                double_queues_[i] = new Queue<double>(*other.double_queues_[i]);
            }
        } else {
            double_queues_ = nullptr;
        }
        
        if (other.count_char_ > 0) {
            char_queues_ = new Queue<char>*[other.count_char_];
            for (int i = 0; i < other.count_char_; ++i) {
                char_queues_[i] = new Queue<char>(*other.char_queues_[i]);
            }
        } else {
            char_queues_ = nullptr;
        }
        
        if (other.count_string_ > 0) {
            string_queues_ = new Queue<string>*[other.count_string_];
            for (int i = 0; i < other.count_string_; ++i) {
                string_queues_[i] = new Queue<string>(*other.string_queues_[i]);
            }
        } else {
            string_queues_ = nullptr;
        }
}
    
void Queue_array::copy_int_queues(const Queue_array& other, Queue<int>**& new_int) const {
    if (other.count_int_ > 0) {
        new_int = new Queue<int>*[other.count_int_];
        for (int i = 0; i < other.count_int_; ++i) {
            new_int[i] = new Queue<int>(*other.int_queues_[i]);
        }
    } else {
        new_int = nullptr;
    }
}

void Queue_array::copy_double_queues(const Queue_array& other, Queue<double>**& new_double) const {
    if (other.count_double_ > 0) {
        new_double = new Queue<double>*[other.count_double_];
        for (int i = 0; i < other.count_double_; ++i) {
            new_double[i] = new Queue<double>(*other.double_queues_[i]);
        }
    } else {
        new_double = nullptr;
    }
}

void Queue_array::copy_char_queues(const Queue_array& other, Queue<char>**& new_char) const {
    if (other.count_char_ > 0) {
        new_char = new Queue<char>*[other.count_char_];
        for (int i = 0; i < other.count_char_; ++i) {
            new_char[i] = new Queue<char>(*other.char_queues_[i]);
        }
    } else {
        new_char = nullptr;
    }
}

void Queue_array::copy_string_queues(const Queue_array& other, Queue<string>**& new_string) const {
    if (other.count_string_ > 0) {
        new_string = new Queue<string>*[other.count_string_];
        for (int i = 0; i < other.count_string_; ++i) {
            new_string[i] = new Queue<string>(*other.string_queues_[i]);
        }
    } else {
        new_string = nullptr;
    }
}

void Queue_array::clear_int_queues() {
    if (int_queues_) {
        for (int i = 0; i < count_int_; ++i) {
            delete int_queues_[i];
        }
        delete[] int_queues_;
        int_queues_ = nullptr;
    }
    count_int_ = 0;
}

void Queue_array::clear_double_queues() {
    if (double_queues_) {
        for (int i = 0; i < count_double_; ++i) {
            delete double_queues_[i];
        }
        delete[] double_queues_;
        double_queues_ = nullptr;
    }
    count_double_ = 0;
}

void Queue_array::clear_char_queues() {
    if (char_queues_) {
        for (int i = 0; i < count_char_; ++i) {
            delete char_queues_[i];
        }
        delete[] char_queues_;
        char_queues_ = nullptr;
    }
    count_char_ = 0;
}

void Queue_array::clear_string_queues() {
    if (string_queues_) {
        for (int i = 0; i < count_string_; ++i) {
            delete string_queues_[i];
        }
        delete[] string_queues_;
        string_queues_ = nullptr;
    }
    count_string_ = 0;
}

void Queue_array::assign_from_copy(Queue<int>** new_int, Queue<double>** new_double,
                                  Queue<char>** new_char, Queue<string>** new_string,
                                  const Queue_array& other) {
    int_queues_ = new_int;
    double_queues_ = new_double;
    char_queues_ = new_char;
    string_queues_ = new_string;
    count_int_ = other.count_int_;
    count_double_ = other.count_double_;
    count_char_ = other.count_char_;
    count_string_ = other.count_string_;
}

Queue_array& Queue_array::operator=(const Queue_array& other) {
    if (this != &other) {
        Queue<int>** new_int = nullptr;
        Queue<double>** new_double = nullptr;
        Queue<char>** new_char = nullptr;
        Queue<string>** new_string = nullptr;
        
        copy_int_queues(other, new_int);
        copy_double_queues(other, new_double);
        copy_char_queues(other, new_char);
        copy_string_queues(other, new_string);
        
        clear_int_queues();
        clear_double_queues();
        clear_char_queues();
        clear_string_queues();
        
        assign_from_copy(new_int, new_double, new_char, new_string, other);
    }
    return *this;
}    
    
Queue_array::Queue_array(Queue_array&& other) noexcept :
        int_queues_(other.int_queues_),
        double_queues_(other.double_queues_),
        char_queues_(other.char_queues_),
        string_queues_(other.string_queues_),
        count_int_(other.count_int_),
        count_double_(other.count_double_),
        count_char_(other.count_char_),
        count_string_(other.count_string_)
    {
        other.int_queues_ = nullptr;
        other.double_queues_ = nullptr;
        other.char_queues_ = nullptr;
        other.string_queues_ = nullptr;
        other.count_int_ = 0;
        other.count_double_ = 0;
        other.count_char_ = 0;
        other.count_string_ = 0;
}

Queue_array& Queue_array::operator=(Queue_array&& other) noexcept {
        if (this != &other) {
           
            if (int_queues_) {
                for (int i = 0; i < count_int_; ++i) {
                    delete int_queues_[i];
                }
                delete[] int_queues_;
            }
            
            if (double_queues_) {
                for (int i = 0; i < count_double_; ++i) {
                    delete double_queues_[i];
                }
                delete[] double_queues_;
            }
            
            if (char_queues_) {
                for (int i = 0; i < count_char_; ++i) {
                    delete char_queues_[i];
                }
                delete[] char_queues_;
            }
            
            if (string_queues_) {
                for (int i = 0; i < count_string_; ++i) {
                    delete string_queues_[i];
                }
                delete[] string_queues_;
            }
            
            int_queues_ = other.int_queues_;
            double_queues_ = other.double_queues_;
            char_queues_ = other.char_queues_;
            string_queues_ = other.string_queues_;
            count_int_ = other.count_int_;
            count_double_ = other.count_double_;
            count_char_ = other.count_char_;
            count_string_ = other.count_string_;

            other.int_queues_ = nullptr;
            other.double_queues_ = nullptr;
            other.char_queues_ = nullptr;
            other.string_queues_ = nullptr;
            other.count_int_ = 0;
            other.count_double_ = 0;
            other.count_char_ = 0;
            other.count_string_ = 0;
        }
        return *this;
}

template int Queue_array::create_queue<int>(Queue<int>*);
template int Queue_array::create_queue<double>(Queue<double>*);
template int Queue_array::create_queue<char>(Queue<char>*);
template int Queue_array::create_queue<string>(Queue<string>*);

template Queue<int>* Queue_array::get_queue<int>(int);
template Queue<double>* Queue_array::get_queue<double>(int);
template Queue<char>* Queue_array::get_queue<char>(int);
template Queue<string>* Queue_array::get_queue<string>(int);

template bool Queue_array::enqueue<int>(int, const int&);
template bool Queue_array::enqueue<double>(int, const double&);
template bool Queue_array::enqueue<char>(int, const char&);
template bool Queue_array::enqueue<string>(int, const string&);

template bool Queue_array::dequeue<int>(int);
template bool Queue_array::dequeue<double>(int);
template bool Queue_array::dequeue<char>(int);
template bool Queue_array::dequeue<string>(int);