#include "../headers/queue.h"
#include "../headers/algorithm.h"
#include "../headers/menu.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <cctype>

template<typename T>
T check_numbers() {
    T number;
    std::string input;
    
    while (true) {
        std::getline(std::cin, input);
        
        if (std::stringstream ss(input); ss >> number && ss.eof()) {
            return number;
        }
        std::cout << "Ошибка. Введите число: ";
    }
}

void print_menu(){
    std::cout << "1 - Введите очередь" << std::endl
              << "2 - Найти элемент" << std::endl
              << "3 - Отсортировать очередь" << std::endl
              << "4 - Вывести очередь" << std::endl
              << "0 - Выход" << std::endl;
}

void enter_queue(Queue& queue){
    std::cout << "Введите целые числа. Для завершения ввода введите пустую строку\n";

    while (true) {
        std::string input;
        std::getline(std::cin, input);

        if (input.empty()) {
            break;
        }
        std::stringstream ss(input);
        int number;
        if (ss >> number && ss.eof()) {
            queue.push(number);
        } else {
            std::cout << "Ошибка. Введите число ещё раз: ";
        }
    }
}

void print_queue(Queue& queue) {
    std::cout << "Ваша очередь:\n";
    bool first = true;
    for (const auto& value : queue) {
        if (!first) std::cout << ", ";
        std::cout << value;
        first = false;
    }
    std::cout << std::endl;
}

void menu(){
    Queue queue;
    int choice = 0;
    int value;
    
    do{
        system("clear");
        print_menu();
        choice = check_numbers<int>();

        switch (choice) {
        case 1:
            system("clear");
            enter_queue(queue);
            break;
        case 2:{
            system("clear");
            print_queue(queue);

            if (queue.empty()) {
                std::cout << "Очередь пуста, искать нечего.\n";
                break;
            }

            std::cout << "Введите число для поиска: ";
            value = check_numbers<int>();

            if (auto it = Algorithm::find(queue.begin(), queue.end(), value); it != queue.end()) {
                std::cout << "Найдено число: " << *it << "\n";
            } else {
                std::cout << "Число не найдено.\n";
            }
            break;
        }
        case 3:
            system("clear");
            if (queue.empty()) {
                std::cout << "Очередь пуста. Сортировка невозможна.\n";
                break;
            }
            print_queue(queue);
            std::cout << "Отсортированная очередь:\n";
            Algorithm::sort(queue);
            print_queue(queue);
            break;
        case 4:
            system("clear");
            print_queue(queue);
            break;
        
        case 0:
            system("clear");
            std::cout << "Выход..." << std::endl;
            break;
        
        default:
            std::cout << "Неверный пункт меню. Введите ещё раз.\n";
        }

        if (choice != 0) {
            std::cout << "\nНажмите Enter для продолжения...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while(choice != 0);
}
