#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <cstring>
#include <limits>

class User {
public:
    User() = default;
    User(const std::string* initials, int number) : surname_(initials[0]), name_(initials[1]), middle_name_(initials[2]), number_worker_(number) {}
    
    void input_in_file(const std::string& file_name, const User& user) const;
    void enter_user(User& user, const std::string& file_name) const;
    
    static User** load_users_from_file(const std::string& file_name, int& user_count);
    static void free_users(User** users, int count);
    
    void display() const;

private:
    std::string surname_;
    std::string name_;
    std::string middle_name_;
    int number_worker_;
    static void reset_user_data(std::string& surname, std::string& name, std::string& middle_name, int& number);
    static void process_data_line(const std::string_view& line, size_t pos, std::string& surname, std::string& name, std::string& middle_name, int& number);
};

#endif