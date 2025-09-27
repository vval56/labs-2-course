#ifndef RUSSIAN_H
#define RUSSIAN_H

#include <cstring>
#include <cstdlib>
#include <vector>

char** get_utf8_chars(const char* str);
size_t utf8_strlen(const char* str);
char* utf8_substr(const char* str, size_t start, size_t length);
char* utf8_char_at(const char* str, size_t index);

#endif