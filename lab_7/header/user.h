#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <cstring>
#include <limits>

class User{
public:
    User() = default;
    User(const std::string * initials, int number) : surname_(initials[0]), name_(initials[1]), middle_name_(initials[2]), number_worker_(number) {}
    void input_in_file(const std::string& file_name, const User& user) const;
    void enter_user(User & user, const std::string& file_name);
private:
    std::string surname_;
    std::string name_;
    std::string middle_name_;
    int number_worker_;
};

#endif