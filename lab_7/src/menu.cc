#include "../header/menu.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <cctype>

bool is_cyrillic_char(unsigned char c1, unsigned char c2) {
    return (c1 == 0xD0 && c2 >= 0x80 && c2 <= 0xBF) || 
           (c1 == 0xD1 && c2 >= 0x80 && c2 <= 0x9F);
}

bool is_only_letters(const std::string& str) {
    if (str.empty()) {
        std::cout << "Строка не может быть пустой!\n";
        return false;
    }
    
    for (size_t i = 0; i < str.length();) {
        auto c = static_cast<unsigned char>(str[i]);
        if (c >= 0xC0) { 
            if (i + 1 >= str.length()) {
                std::cout << "Некорректный UTF-8 символ\n";
                return false;
            }
            
            auto c2 = static_cast<unsigned char>(str[i + 1]);
            
            if (!is_cyrillic_char(c, c2)) {
                std::cout << "Недопустимый символ: допускаются только русские буквы\n";
                return false;
            }
            
            i += 2;
        }
        else if (!isalpha(c) && c != ' ' && c != '-') {
            std::cout << "Недопустимый символ: '" << c << "'\n";
            return false;
        }
        else {
            i++;
        }
    }
    
    return true;
}

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
    std::cout << "1 - Введите пользователя" << std::endl
              << "2 - Посмотреть пользователей в файле" << std::endl
              << "0 - Выход" << std::endl;
}

void print_file(const std::string file_name){
    std::ifstream file(file_name);
    std::string line;

    while(std::getline(file, line)){
        std::cout << line << std::endl;
    }
    
    file.close();
}

void menu(){
    User user;
    int choice = 0;
    std::string file_name = "users.txt";
    std::ofstream clear_file(file_name);
    clear_file.close();

    do{
        system("clear");
        print_menu();
        choice = check_numbers<int>();

        switch (choice) {
        case 1:
            system("clear");
            user.enter_user(user, file_name);
            break;
        case 2:
            system("clear");
            print_file(file_name);
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
