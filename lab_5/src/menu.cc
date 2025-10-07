#include "../headers/queues.h"
#include <iostream>
#include <cctype>
#include <sstream>
#include <limits>
#include <vector>

using namespace std;

template<typename Type>
Type check_numbers() {
    Type number;
    string input;
    
    while (true) {
        getline(cin, input);
        
        if (stringstream ss(input);ss >> number && ss.eof()) {
            return number;
        }
        cout << "Ошибка. Введите число: ";
    }
}

void print_menu(){
    cout << "Меню работы с очередями\n"
         << "1 - Создать очередь\n"
         << "2 - Посмотреть все очереди\n"
         << "3 - Добавить элемент в очередь\n"
         << "4 - Удалить элемент из очереди\n"
         << "0 - Выход\n";
}

bool isInt(const string &s) {
    if (s.empty()) return false;
    size_t i = 0;
    if (s[0] == '-' || s[0] == '+') i++;
    for (; i < s.size(); ++i)
        if (!isdigit(s[i])) return false;
    return true;
}

bool isDouble(const string &s) {
    bool dot = false;
    if (s.empty()) return false;
    size_t i = 0;
    if (s[0] == '-' || s[0] == '+') i++;
    for (; i < s.size(); ++i) {
        if (s[i] == '.') {
            if (dot) return false;
            dot = true;
        } else if (!isdigit(s[i])) return false;
    }
    return dot;
}

template<typename T>
void finalize_queue_creation(Queue_array& queues, Queue<T>* q, const string& type_name) {
    int index = queues.create_queue(q);
    cout << "Создана очередь типа " << type_name << " (индекс: " << index << "):\n";
    q->print();
}

vector<string> read_input_lines() {
    cout << "Введите элементы (пустая строка — завершение):\n";
    
    vector<string> inputs;
    string line;
    while (true) {
        getline(cin, line);
        if (line.empty()) break;
        inputs.push_back(line);
    }
    
    return inputs;
}

void create_int_queue(Queue_array& queues, const vector<string>& inputs) {
    auto q = new Queue<int>();
    
    for (auto &val : inputs) {
        if (!isInt(val)) {
            cout << "Ошибка: введён элемент, не являющийся int!\n";
            delete q;
            return;
        }
        q->enqueue(stoi(val));
    }
    
    finalize_queue_creation(queues, q, "int");
}

void create_double_queue(Queue_array& queues, const vector<string>& inputs) {
    auto q = new Queue<double>();
    
    for (auto &val : inputs) {
        if (!(isDouble(val) || isInt(val))) {
            cout << "Ошибка: введён элемент, не являющийся double!\n";
            delete q;
            return;
        }
        q->enqueue(stod(val));
    }
    
    finalize_queue_creation(queues, q, "double");
}

void create_char_queue(Queue_array& queues, const vector<string>& inputs) {
    auto q = new Queue<char>();
    
    for (auto &val : inputs) {
        if (val.size() != 1) {
            cout << "Ошибка: введён элемент, не являющийся символом!\n";
            delete q;
            return;
        }
        q->enqueue(val[0]);
    }
    
    finalize_queue_creation(queues, q, "char");
}

void create_string_queue(Queue_array& queues, const vector<string>& inputs) {
    auto q = new Queue<string>();
    
    for (auto &val : inputs) {
        q->enqueue(val);
    }
    
    finalize_queue_creation(queues, q, "string");
}

void create_queue_by_type(Queue_array& queues, const vector<string>& inputs) {
    string first = inputs[0];
    
    if (isInt(first)) {
        create_int_queue(queues, inputs);
    }
    else if (isDouble(first)) {
        create_double_queue(queues, inputs);
    }
    else if (first.size() == 1) {
        create_char_queue(queues, inputs);
    }
    else {
        create_string_queue(queues, inputs);
    }
}

void create_queue_auto(Queue_array& queues) {
    vector<string> inputs = read_input_lines();
    
    if (inputs.empty()) {
        cout << "Очередь пуста.\n";
        return;
    }

    create_queue_by_type(queues, inputs);
}

template<typename T>
void handle_successful_addition(Queue_array& queues, int index, const string& type_name) {
    cout << "Элемент добавлен!\n";
    Queue<T>* q = queues.get_queue<T>(index);
    if (q) {
        cout << "Обновленная очередь " << type_name << ": ";
        q->print();
    }
}


int get_queue_type_choice() {
    cout << "Выберите тип очереди:\n"
         << "1 - int\n"
         << "2 - double\n"
         << "3 - char\n"
         << "4 - string\n"
         << "0 - Отмена\n";
    
    int type_choice = check_numbers<int>();
    if (type_choice < 0 || type_choice > 4) {
        cout << "Неверно введено число";
        return 0;
    }
    
    if (type_choice == 0) {
        cout << "Выход";
        return 0;
    }
    
    return type_choice;
}

void add_int_element(Queue_array& queues, int index) {
    int value = check_numbers<int>();
    if (queues.enqueue(index, value)) {
        handle_successful_addition<int>(queues, index, "int");
    } else {
        cout << "Очередь не найдена!\n";
    }
}

void add_double_element(Queue_array& queues, int index) {
    double value = check_numbers<double>();
    if (queues.enqueue(index, value)) {
        handle_successful_addition<double>(queues, index, "double");
    } else {
        cout << "Очередь не найдена!\n";
    }
}
void add_char_element(Queue_array& queues, int index) {
    char value;
    string input;
    getline(cin, input);
    if (!input.empty()) value = input[0];
    
    if (queues.enqueue(index, value)) {
        handle_successful_addition<char>(queues, index, "char");
    } else {
        cout << "Очередь не найдена!\n";
    }
}

void add_string_element(Queue_array& queues, int index) {
    string value;
    getline(cin, value);
    
    if (queues.enqueue(index, value)) {
        handle_successful_addition<string>(queues, index, "string");
    } else {
        cout << "Очередь не найдена!\n";
    }
}

void process_element_addition(Queue_array& queues, int type_choice, int index) {
    cout << "Введите значение для добавления: ";
    
    switch (type_choice) {
        case 1: add_int_element(queues, index); break;
        case 2: add_double_element(queues, index); break;
        case 3: add_char_element(queues, index); break;
        case 4: add_string_element(queues, index); break;
        default: cout << "Неверно введено число\n";
    }
}

void add_element_to_queue(Queue_array& queues) {
    queues.print_all();
    
    int type_choice = get_queue_type_choice();
    if (type_choice == 0) return;
    
    cout << "Введите индекс очереди: ";
    int index = check_numbers<int>();
    
    process_element_addition(queues, type_choice, index);
}

void remove_element_from_queue(Queue_array& queues) {
    queues.print_all();
    cout << "Выберите тип очереди:\n"
         << "1 - int\n"
         << "2 - double\n"
         << "3 - char\n"
         << "4 - string\n"
         << "0 - Отмена\n";
    
    int type_choice = check_numbers<int>();
    if (type_choice < 1 || type_choice > 4){
        cout << "Неверно введено число";
        return;
    }

    cout << "Введите индекс очереди: ";
    int index = check_numbers<int>();
    
    bool success = false;
    
    switch (type_choice) {
        case 1:
            success = queues.dequeue<int>(index);
            break;
        case 2:
            success = queues.dequeue<double>(index);
            break;
        case 3:
            success = queues.dequeue<char>(index);
            break;
        case 4:
            success = queues.dequeue<string>(index);
            break;
        default:
            cout << "Неверно введен индекс\n";
            break;

    }
    
    if (success) {
        cout << "Элемент удален!\n";
        switch (type_choice) {
            case 1: {
                if (Queue<int>* q = queues.get_queue<int>(index)) { cout << "Обновленная очередь: "; q->print(); }
                break;
            }
            case 2: {
                if (Queue<double>* q = queues.get_queue<double>(index)) { cout << "Обновленная очередь: "; q->print(); }
                break;
            }
            case 3: {
                if (Queue<char>* q = queues.get_queue<char>(index)) { cout << "Обновленная очередь: "; q->print(); }
                break;
            }
            case 4: {
                if (Queue<string>* q = queues.get_queue<string>(index)) { cout << "Обновленная очередь: "; q->print(); }
                break;
            }
            default:{
                cout << "Очередь не найдена или пуста!\n";
                break;
            }
        }
    } else {
        cout << "Очередь не найдена или пуста!\n";
    }
}

template<typename Type>
void menu(){
    int choice = 0;
    Queue_array queues;
    
    do{
        system("clear");
        print_menu();
        choice = check_numbers<int>();

        switch (choice){
        case 1:
            system("clear");
            create_queue_auto(queues);
            break;
            
        case 2:
            system("clear");
            queues.print_all();
            break;
            
        case 3:
            system("clear");
            add_element_to_queue(queues);
            break;
            
        case 4:
            system("clear");
            remove_element_from_queue(queues);
            break;

        case 0:
            system("clear");
            cout << "Выход из программы...\n";
            break;
        
        default:
            cout << "Неверный выбор! Попробуйте снова.\n";
        }

        if (choice != 0) {
            cout << "\nНажмите Enter для продолжения...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while(choice != 0);
}

template void menu<int>();
template void menu<double>();
template void menu<char>();
template void menu<std::string>();