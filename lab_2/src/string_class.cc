#include "../header/string_class.h"
#include <iostream>
#include <cstring>
#include <string>
#include <limits>

using namespace std;

String::String() : text_(new char[1]), length_(0) {
    text_[0] = '\0';
}

String::String(const char* text) {
    if (text != nullptr) {
        length_ = strlen(text);
        text_ = new char[length_ + 1];
        strcpy(text_, text);
    } else {
        length_ = 0;
        text_ = new char[1];
        text_[0] = '\0';
    }
}

String::~String() {
    delete[] text_;
}

String::String(const String& other) : length_(other.length_) {
    text_ = new char[length_ + 1];
    strcpy(text_, other.text_);
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] text_; 
        
        length_ = other.length_;
        text_ = new char[length_ + 1];
        strcpy(text_, other.text_);
    }
    return *this;
}

String::String(String&& other) noexcept : text_(other.text_), length_(other.length_) {
    other.text_ = nullptr;
    other.length_ = 0;
}

String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        delete[] text_;
        
        text_ = other.text_;
        length_ = other.length_;
        
        other.text_ = nullptr;
        other.length_ = 0;
    }
    return *this;
}

bool String::operator!() const {
    return length_ == 0;
}

String String::operator()(int index1, int index2) const {
    if (index1 < 0 || index2 >= length_ || index1 > index2) {
        return String();
    }
    
    int substr_length = index2 - index1 + 1;
    char* substring = new char[substr_length + 1];
    
    for (int i = 0; i < substr_length; i++) {
        substring[i] = text_[index1 + i];
    }
    substring[substr_length] = '\0';
    
    String result(substring);
    delete[] substring;
    return result;
}

char String::operator[](int index) const {
    if (index < 0 || index >= length_) {
        return '\0';
    }
    return text_[index];
}

char& String::operator[](int index) {
    if (index < 0 || index >= length_) {
        static char dummy = '\0';
        return dummy;
    }
    return text_[index];
}

int String::Length() const {
    return length_;
}

ostream& operator<<(ostream& output_stream, const String& line) {
    output_stream << line.text_;
    return output_stream; 
}

istream& operator>>(istream& input_stream, String& line) {
    string complete_input;
    string temp_line;
    int empty_line_count = 0;
    
    while (empty_line_count < 2) {
        char buffer[1024];
        input_stream.getline(buffer, 1024);
        
        temp_line = buffer;
        
        if (temp_line.empty()) {
            empty_line_count++;
        } else {
            empty_line_count = 0;
            if (!complete_input.empty()) {
                complete_input += '\n';
            }
            complete_input += temp_line;
        }
        
        if (input_stream.fail() && !input_stream.eof()) {
            input_stream.clear();
            input_stream.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    delete[] line.text_;
    line.length_ = complete_input.length();
    line.text_ = new char[line.length_ + 1];
    strcpy(line.text_, complete_input.c_str());
    
    return input_stream;
}