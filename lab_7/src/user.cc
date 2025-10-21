#include "../header/user.h"
#include "../header/menu.h"
#include <fstream>
#include <sstream>

void User::input_in_file(const std::string& file_name, const User& user) const {
    std::ofstream file(file_name, std::ios::app);

    file << "Фамилия: " << user.surname_ << std::endl
         << "Имя: " << user.name_ << std::endl
         << "Отчество: " << user.middle_name_ << std::endl
         << "Номер пользователя: " << user.number_worker_ << std::endl
         << "==============================" << std::endl;

    file.close();
}

void User::enter_user(User& user, const std::string& file_name) const {
    std::string temp_line;
    int number = 0;

    do {
        std::cout << "Введите фамилию: ";
        std::getline(std::cin, temp_line);
    } while (!is_only_letters(temp_line));
    user.surname_ = temp_line;

    do {
        std::cout << "Введите имя: ";
        std::getline(std::cin, temp_line);
    } while (!is_only_letters(temp_line));
    user.name_ = temp_line;

    do {
        std::cout << "Введите отчество: ";
        std::getline(std::cin, temp_line);
    } while (!is_only_letters(temp_line));
    user.middle_name_ = temp_line;

    std::cout << "Введите номер: ";
    number = check_numbers<int>();
    user.number_worker_ = number;

    input_in_file(file_name, user);
}
void User::display() const {
    std::cout << "\nФамилия: " << surname_ 
              << ",\nИмя: " << name_ 
              << ",\nОтчество: " << middle_name_ 
              << ",\nНомер: " << number_worker_ << std::endl;
}

User** User::load_users_from_file(const std::string& file_name, int& user_count) {
    std::ifstream file(file_name, std::ios::binary);
    if (!file.is_open()) {
        user_count = 0;
        return nullptr;
    }

    user_count = 0;
    std::string line;
    
    while (std::getline(file, line)) {
        if (line.length() >= 0 && line.find("=") != std::string::npos) {
            user_count++;
        }
    }
    
    file.close();

    if (user_count == 0) {
        return nullptr;
    }

    User** users = new User*[user_count];
    for (int i = 0; i < user_count; i++) {
        users[i] = nullptr;
    }

    file.open(file_name);
    int current_user = 0;
    std::string surname, name, middle_name;
    int number = 0;

    while (std::getline(file, line)) {
        size_t pos = line.find(": ");
        if (pos != std::string::npos) {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 2);
            
            value.erase(0, value.find_first_not_of(" \t"));
            value.erase(value.find_last_not_of(" \t") + 1);
            
            if (key.find("Фамилия") != std::string::npos) {
                surname = value;
            } else if (key.find("Имя") != std::string::npos) {
                name = value;
            } else if (key.find("Отчество") != std::string::npos) {
                middle_name = value;
            } else if (key.find("Номер") != std::string::npos) {
                try {
                    number = std::stoi(value);
                } catch (const std::exception& e) {
                    number = 0;
                }
            }
        }
        else if (line.find("=") != std::string::npos) {
            if (current_user < user_count && !surname.empty() && !name.empty()) {
                std::string initials[3] = {surname, name, middle_name};
                users[current_user] = new User(initials, number);
                current_user++;
            }
            
            surname.clear();
            name.clear();
            middle_name.clear();
            number = 0;
        }
    }

    file.close();
    
    user_count = current_user;
    
    if (user_count == 0) {
        delete[] users;
        return nullptr;
    }
    
    return users;
}

void User::free_users(User** users, int count) {
    if (users == nullptr) return;
    
    for (int i = 0; i < count; i++) {
        delete users[i];
    }
    delete[] users;
}