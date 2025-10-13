#include "../header/user.h"
#include "../header/menu.h"
#include <fstream>

void User::input_in_file(const std::string file_name, const User& user) {
    std::ofstream file(file_name, std::ios::app);

    file << "Фамилия: " << user.surname_ << std::endl
         << "Имя: " << user.name_ << std::endl
         << "Отчество: " << user.middle_name_ << std::endl
         << "Номер пользователя: " << user.number_worker_ << std::endl
         << "==============================" << std::endl;

    file.close();
}

void User::enter_user(User & user, const std::string file_name){
    std::string temp_line;
    int number = 0;

    do{
        std::cout << "Введите фамилию: ";
        std::getline(std::cin, temp_line);
    }while(!is_only_letters(temp_line));
    user.surname_ = temp_line;

    do{
        std::cout << "Введите имя: ";
        std::getline(std::cin, temp_line);
    }while(!is_only_letters(temp_line));
    user.name_ = temp_line;

    do{
        std::cout << "Введите отчество: ";
        std::getline(std::cin, temp_line);
    }while(!is_only_letters(temp_line));
    user.middle_name_ = temp_line;

    std::cout << "Введите номер: ";
    number = check_numbers<int>();
    user.number_worker_ = number;

    input_in_file(file_name, user);
}