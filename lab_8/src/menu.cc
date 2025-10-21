#include "../headers/menu.h"

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

template<typename T>
void enter_queue(Queue<T>& queue){
    std::cout << "Введите числа. Для завершения ввода введите пустую строку\n";

    queue.clear();
    
    while (true) {
        std::string input;
        std::getline(std::cin, input);

        if (input.empty()) {
            break;
        }
        std::stringstream ss(input);
        T number;
        if (ss >> number && ss.eof()) {
            queue.push(number);
        } else {
            std::cout << "Ошибка. Введите число ещё раз: ";
        }
    }
}

template<typename T>
void print_queue(Queue<T>& queue) {
    std::cout << "Ваша очередь:\n";
    bool first = true;
    auto it = queue.begin();
    while (it != queue.end()) {
        if (!first) std::cout << ", ";
        std::cout << *it;
        first = false;
        ++it;
    }
    std::cout << std::endl;
}

template<typename T>
void menu(){
    Queue<T> queue;
    int choice = 0;
    T value; 

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

            std::cout << "Введите значение для поиска: ";
            value = check_numbers<T>();

            if (auto it = Algorithm<T>::find(queue.begin(), queue.end(), value); it != queue.end()) {
                std::cout << "Найдено: " << *it << "\n";
            } else {
                std::cout << "Значение не найдено.\n";
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
            Algorithm<T>::sort(queue);
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

template int check_numbers<int>();
template double check_numbers<double>();
template char check_numbers<char>();

template void enter_queue<int>(Queue<int>& queue);
template void enter_queue<double>(Queue<double>& queue);
template void enter_queue<char>(Queue<char>& queue);

template void print_queue<int>(Queue<int>& queue);
template void print_queue<double>(Queue<double>& queue);
template void print_queue<char>(Queue<char>& queue);

template void menu<int>();