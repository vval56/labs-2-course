#include "../header/russian.h"
#include <cstddef>

char** get_utf8_chars(const char* str) {
    size_t len = strlen(str);
    std::vector<char*> chars_vector;
    
    for (size_t i = 0; i < len;) {
        auto c = static_cast<std::byte>(str[i]);
        int char_len = 1;
        
        if ((c & std::byte{0xF0}) == std::byte{0xF0}) char_len = 4;
        else if ((c & std::byte{0xE0}) == std::byte{0xE0}) char_len = 3;
        else if ((c & std::byte{0xC0}) == std::byte{0xC0}) char_len = 2;
        else char_len = 1;
        
        auto character = static_cast<char*>(malloc(char_len + 1));
        
        for (int j = 0; j < char_len; j++) {
            character[j] = str[i + j];
        }
        character[char_len] = '\0';  
        
        chars_vector.push_back(character);
        i += char_len;
    }
    
    auto result = static_cast<char**>(malloc((chars_vector.size() + 1) * sizeof(char*)));
    for (size_t i = 0; i < chars_vector.size(); i++) {
        result[i] = chars_vector[i];
    }
    result[chars_vector.size()] = nullptr; 
    
    return result;
}

size_t utf8_strlen(const char* str) {
    size_t count = 0;
    size_t len = strlen(str);
    
    for (size_t i = 0; i < len;) {
        auto c = static_cast<std::byte>(str[i]);
        int char_len = 1;
        
        if ((c & std::byte{0xF0}) == std::byte{0xF0}) char_len = 4;
        else if ((c & std::byte{0xE0}) == std::byte{0xE0}) char_len = 3;
        else if ((c & std::byte{0xC0}) == std::byte{0xC0}) char_len = 2;
        else char_len = 1;
        
        count++;
        i += char_len;
    }
    
    return count;
}

char* utf8_substr(const char* str, size_t start, size_t length) {
    char** chars = get_utf8_chars(str);
    
    if (size_t total_chars = utf8_strlen(str); start >= total_chars) {
        for (size_t i = 0; chars[i] != nullptr; i++) {
            free(chars[i]);
        }
        free(chars);
        auto empty = static_cast<char*>(malloc(1));
        empty[0] = '\0';
        return empty;
    }
    
    size_t total_bytes = 0;
    for (size_t i = start; i < start + length && chars[i] != nullptr; i++) {
        total_bytes += strlen(chars[i]);
    }

    auto result = static_cast<char*>(malloc(total_bytes + 1));
    result[0] = '\0';  
    
    for (size_t i = start; i < start + length && chars[i] != nullptr; i++) {
        strcat(result, chars[i]);
    }
    
    for (size_t i = 0; chars[i] != nullptr; i++) {
        free(chars[i]);
    }
    free(chars);
    
    return result;
}

char* utf8_char_at(const char* str, size_t index) {
    char** chars = get_utf8_chars(str);
    
    if (size_t total_chars = utf8_strlen(str); index >= total_chars) {
        for (size_t i = 0; chars[i] != nullptr; i++) {
            free(chars[i]);
        }
        free(chars);
        
        auto empty = static_cast<char*>(malloc(1));
        empty[0] = '\0';
        return empty;
    }

    auto result = static_cast<char*>(malloc(strlen(chars[index]) + 1));
    strcpy(result, chars[index]);
    
    for (size_t i = 0; chars[i] != nullptr; i++) {
        free(chars[i]);
    }
    free(chars);
    
    return result;
}