#ifndef STRING_CLASS_H
#define STRING_CLASS_H

#include <iostream>
#include <cstring>

class String {
public:
    String();
    String(const char* text);
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

    friend std::ostream& operator<<(std::ostream& output_stream, const String& line);
    friend std::istream& operator>>(std::istream& input_stream, String& line);

private:
    char* text_;
    int length_;
};

#endif