#include "../include/menu.h"
#include "../include/array_exceptions.h"
#include <iostream>
#include <sstream>
#include <limits>
#include <vector>

using namespace std;

template<typename T>
T check_numbers() {
    T number;
    string input;
    
    while (true) {
        getline(cin, input);
        
        if (stringstream ss(input); ss >> number && ss.eof()) {
            return number;
        }
        cout << "Ошибка. Введите число: ";
    }
}

void hand_input(Array& array) {
    int* temp_arr = nullptr;  
    int count = 0;
    bool incorrect_input = false;           
    
    cout << "Ввод массива" << endl;
    cout << "Вводите числа. Для завершения ввода введите нечисловой символ или пустую строку:\n";
    
    while (!incorrect_input) {
        string input;
        getline(cin, input);

        if (input.empty()) {
            incorrect_input = true;
            continue;
        }

        stringstream ss(input);
        int number;
        if (ss >> number && ss.eof()) {
            auto new_arr = new int[count + 1];
            for (int i = 0; i < count; i++) {
                new_arr[i] = temp_arr[i];
            }
            new_arr[count] = number;
            delete[] temp_arr;
            temp_arr = new_arr;
            count++;
        } else {
            incorrect_input = true;
        }
    }

    if (count > 0) {
        array = Array(temp_arr, count);
        cout << "Массив сохранен. Размер: " << count << endl;
    } else {
        cout << "Массив пуст." << endl;
    }

    delete[] temp_arr;
}

void print_menu() {
    cout << "\nМеню работы с массивом\n"
         << "1 - Ввести массив\n"
         << "2 - Посмотреть массив\n"
         << "3 - Добавить элемент в массив\n"
         << "4 - Посмотреть элемент по индексу\n"
         << "5 - Удалить элемент по индексу\n"
         << "0 - Выход\n"
         << "Ведите число от 0 до 5: ";
}

void add_element_array(Array & array){
    cout << "Введите значение для добавления: ";
    int value = check_numbers<int>();
    array.add_element(value);
    cout << "Элемент добавлен." << endl;
    array.print();
}

void show_element_index(Array array){
    cout << "Введите индекс: ";
    int index = check_numbers<int>();
    try {
        int value = array.get_element(index);
        cout << "Элемент с индексом " << index << ": " << value << endl;
    } catch (const Array_exception &error) {
        cout << "Ошибка: " << error.what() << endl;
    }
}

void print_array_safe(const Array& array) {
    try {
        array.print();
    } catch (const Array_exception error) {
        error;
        cout << "Ошибка при выводе массива: " << error.what() << endl;
    }
}

void delete_element_array(Array& array) {
    cout << "Введите индекс для удаления: ";
    int index = check_numbers<int>();
    
    try {
        array.delete_element(index);
        cout << "Элемент удален." << endl;
        print_array_safe(array);
    } catch (const Array_exception &error) {
        cout << "Ошибка при удалении: " << error.what() << endl;
    }   
}

void menu() {
    int choice = 0;
    Array array;

    do {
        system("clear");
        print_menu();
        choice = check_numbers<int>();

        switch (choice) {
        case 1:
            system("clear");
            hand_input(array);
            break;
        
        case 2:
            system("clear");
            try {
                array.print();
            } catch (const Array_exception &error) {
                cout << "Ошибка: " << error.what() << endl;
            }
            break;
            
        case 3: {
            system("clear");
            try {
                array.print();
            } catch (const Array_exception &error) {
                cout << "Ошибка: " << error.what() << endl;
                break;
            }
            add_element_array(array);
            break;
        }
            
        case 4: {
            system("clear");
            try {
                array.print();
            } catch (const Array_exception &error) {
                cout << "Ошибка: " << error.what() << endl;
                break;
            }
            show_element_index(array);
            break;
        }
            
        case 5: {
            system("clear");
            try {
                array.print();
            } catch (const Array_exception &error) {
                cout << "Ошибка: " << error.what() << endl;
                break;
            }
            delete_element_array(array);
            break;
        }
            
        case 0:
            system("clear");
            cout << "Выход..." << endl;
            break;
            
        default:
            cout << "Неверный пункт меню. Введите ещё раз.\n";
        }
        
        if (choice != 0) {
            cout << "\nНажмите Enter для продолжения...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice != 0);
}