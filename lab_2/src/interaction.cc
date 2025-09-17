#include "../header/interacton.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int check_int() {
    int number;
    bool valid = false;
    
    while (!valid) {
        if (cin >> number) {
            if (cin.peek() == '\n') {
                valid = true;
            } else {
                cout << "Ошибка. Введите число.";
            }
        } else {
            cout << "Ошибка. Введите число.";
        }
        
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    return number;
}

void display_menu() {
    cout << "\nМЕНЮ ТЕСТИРОВАНИЯ КЛАССА STRING \n";
    cout << "1. Создать пустую строку\n";
    cout << "2. Создать строку из текста\n";
    cout << "3. Проверить пуста ли строка (оператор !)\n";
    cout << "4. Получить подстроку (оператор ())\n";
    cout << "5. Получить символ по индексу (оператор [])\n";
    cout << "6. Изменить символ по индексу\n";
    cout << "7. Вывести длину строки\n";
    cout << "8. Вывести строку (оператор <<)\n";
    cout << "9. Ввести строку (оператор >>)\n";
    cout << "10. Копировать строку (конструктор копирования)\n";
    cout << "11. Переместить строку (конструктор переноса)\n";
    cout << "12. Показать текущую строку\n";
    cout << "0. Выход\n";
    cout << "Выберите опцию: ";
}

void create_empty_line(String & Text){
    Text = String();
    cout << "Создана пустая строка\n";
}

void input_string(String & Text){
    cout << "Введите текст: ";
    char input[100];
    cin.getline(input, 100);
    Text = String(input);
    cout << "Создана строка: '" << Text << "'\n";
}

void detect_empty_line(const String & Text){
    cout << "Текущая строка: '" << Text << "'\n";
    if (!Text) {
        cout << "Строка ПУСТАЯ\n";
    } else {
        cout << "Строка НЕ пустая\n";
    }
}

void get_substring(const String & Text){
    cout << "Текущая строка: '" << Text << "'\n";
    
                
    cout << "Введите начальный индекс (от 0): ";
    int start = check_int();
    cout << "Введите конечный индекс (до " << Text.Length() - 1 << "): ";
    int end = check_int();
                
    String Substring = Text(start, end);
    cout << "Подстрока: '" << Substring << "'\n";
}

void get_symbol(String Text){
    cout << "Текущая строка: '" << Text << "'\n";
    cout << "Введите индекс (от 1 до " << Text.Length() << "): ";
    int index = check_int();
    index--;             
    cout << "Символ по индексу " << index << ": '" << Text[index] << endl;
}

void change_symbol(String &Text){
    cout << "Текущая строка: '" << Text << "'\n";

    cout << "Введите индекс для изменения (от 0 до " << Text.Length() - 1 << "): ";
    int index = check_int();
                
    cout << "Введите новый символ: ";
    char new_symbol;
    cin >> new_symbol;
    cin.ignore();
                
    Text[index] = new_symbol;
    cout << "Измененная строка: '" << Text << "'\n";
}

void copy_str(const String & Text){
    String copy = Text;
    cout << "Оригинал: '" << Text << "'\n";
    cout << "Копия: '" << copy << "'\n";
}

void menu() {
    String Line;
    int choice;
    
    do {
        display_menu();
        choice = check_int();
        
        switch (choice) {
            case 1: {
                system("clear");
                create_empty_line(Line);
                break;
            }
                
            case 2: {
                system("clear");
                input_string(Line);
                break;
            }
                
            case 3: {
                system("clear");
                detect_empty_line(Line);
                break;
            }
                
            case 4: {
                system("clear");
                if (!Line) {
                    cout << "Строка пустая, невозможно получить подстроку\n";
                    break;
                }
                get_substring(Line);
                break;
            }
                
            case 5: {
                system("clear");
                if (!Line) {
                    cout << "Строка пустая, невозможно получить символ\n";
                    break;
                }
                get_symbol(Line);
                break;
            }
                
            case 6: {
                system("clear");
                if (!Line) {
                    cout << "Строка пустая, невозможно изменить символ\n";
                    break;
                }
                change_symbol(Line);
                break;
            }
                
            case 7: {
                cout << "Текущая строка: '" << Line << "'\n";
                cout << "Длина: " << Line.Length() << " символов\n";
                break;
            }
                
            case 8: {
                cout << "Текущая строка: ";
                cout << Line << endl;
                break;
            }
                
            case 9: {
                cout << "Введите текст (дважды Enter для завершения):\n";
                cin >> Line;
                cout << "Введенная строка: '" << Line << "'\n";
                break;
            }
                
            case 10: {
                if (!Line) {
                    cout << "Текущая строка пустая, нечего копировать\n";
                    break;
                }
                
                
                break;
            }
                
            case 11: {
                if (Line.Length() == 0) {
                    cout << "Текущая строка пустая, нечего перемещать\n";
                    break;
                }
                
                cout << "До перемещения: '" << Line << "'\n";
                
                String moved = std::move(Line);
                cout << "После перемещения:\n";
                cout << "Перемещенная строка: '" << moved << "'\n";
                cout << "Оригинал (должен быть пустым): '" << Line << "'\n";
                Line = std::move(moved);
                break;
            }
                
            case 12: {
                cout << "Ваша строка: '" << Line << "'\n";
                cout << "Длина: " << Line.Length() << " символов\n";
                break;
            }
                
            case 0:
                cout << "Выход из программы...\n";
                break;
                
            default:
                cout << "Неверный выбор! Попробуйте снова.\n";
        }
        
        if (choice != 0) {
            cout << "\nНажмите Enter для продолжения...";
            cin.get();
        }
        
    } while (choice != 0);
}