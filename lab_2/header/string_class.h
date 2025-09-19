#ifndef STRING_CLASS_H
#define STRING_CLASS_H

#include <iostream>
#include <cstring>
#include <string> 
#include <limits>  

class String {
public:
    String();
    explicit String(const char* text);
    virtual ~String();
    String(const String& other);
    String& operator=(const String& other);
    String(String&& other) noexcept;
    String& operator=(String&& other) noexcept;
    
    bool operator!() const;
    String operator()(int index1, int index2) const;
    char operator[](int index) const;
    char& operator[](int index);
    int Length() const; 

    friend std::ostream& operator<<(std::ostream& output_stream, const String& line) {
        output_stream << line.text_;
        return output_stream; 
    }
    


    friend std::istream& operator>>(std::istream& input_stream, String& line) {
        std::string complete_input;
        int empty_line_count = 0;
        
        while (empty_line_count < 2 && input_stream) {
            std::string current_line;

            if (!std::getline(input_stream, current_line)) {
                if (input_stream.eof()) {
                    break;
                }

                input_stream.clear();
                input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            
            if (current_line.empty()) {
                empty_line_count++;
            } else {
                empty_line_count = 0;
                if (!complete_input.empty()) {
                    complete_input += '\n';
                }
                complete_input += current_line;
            }
        }

        delete[] line.text_;
        line.length_ = complete_input.size();
        line.text_ = new char[line.length_ + 1];
        std::strncpy(line.text_, complete_input.c_str(), line.length_);
        line.text_[line.length_] = '\0'; 
        
        return input_stream;
    }

private:
    char* text_;
    int length_;
};

#endif