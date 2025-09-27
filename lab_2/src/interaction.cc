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
    cout << "\nМЕНЮ КЛАССА STRING \n";
    cout << "1. Проверить пуста ли строка (оператор !)\n";
    cout << "2. Получить подстроку (оператор ())\n";
    cout << "3. Получить символ по индексу (оператор [])\n";
    cout << "4. Вывести длину строки\n";
    cout << "5. Вывести строку (оператор <<)\n";
    cout << "6. Ввести строку (оператор >>)\n";
    cout << "7. Копировать строку (конструктор копирования)\n";
    
    cout << "0. Выход\n";
    cout << "Выберите опцию: ";
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
    
    cout << "Введите начальный индекс (от 0 до " << Text.Length() - 1 << "): ";
    int start;
    do{
        start = check_int();
        if(start < 0 || start >= Text.Length()){
            cout << "Неверный ввод индекса. Допустимый диапазон: 0-" << Text.Length() - 1 << ": ";
        }
    }while(start < 0 || start >= Text.Length());

    cout << "Введите конечный индекс (от " << start << " до " << Text.Length() - 1 << "): ";
    int end;
    do{
        end = check_int();
        if(end < start || end >= Text.Length()){
            cout << "Неверный ввод индекса. Допустимый диапазон: " << start << "-" << Text.Length() - 1 << ": ";
        }
    }while(end < start || end >= Text.Length());
                
    String Substring = Text(start, end);
    cout << "Подстрока: '" << Substring << "'\n";
}

void get_symbol(const String & Text){
    cout << "Текущая строка: '" << Text << "'\n";
    cout << "Введите индекс (от 0 до " << Text.Length() - 1 << "): ";
    int index;
    do{
        index = check_int();
        if(index < 0 || index >= Text.Length()){
            cout << "Неверный ввод индекса. Допустимый диапазон: 0-" << Text.Length() - 1 << ": ";
        }
    }while(index < 0 || index >= Text.Length());        
    
    cout << "Символ по индексу " << index << ": '" << Text[index] << "'" << endl;
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
        system("clear");
        display_menu();
        choice = check_int();
        
        switch (choice) {                
            case 1: {
                system("clear");
                detect_empty_line(Line);
                break;
            }
                
            case 2: {
                system("clear");
                if (!Line) {
                    cout << "Строка пустая, невозможно получить подстроку\n";
                    break;
                }
                get_substring(Line);
                break;
            }
                
            case 3: {
                system("clear");
                if (!Line) {
                    cout << "Строка пустая, невозможно получить символ\n";
                    break;
                }
                get_symbol(Line);
                break;
            }
                
            case 4: {
                system("clear");
                cout << "Текущая строка: '" << Line << "'\n";
                cout << "Длина: " << Line.Length() << " символов\n";
                break;
            }
                
            case 5: {
                system("clear");
                cout << "Текущая строка: ";
                cout << Line << endl;
                break;
            }
                
            case 6: {
                system("clear");
                cout << "Введите текст (дважды Enter для завершения):\n";
                cin >> Line;
                cout << "Введенная строка: '" << Line << "'\n";
                break;
            }
                
            case 7: {
                if (!Line) {
                    cout << "Текущая строка пустая, нечего копировать\n";
                    break;
                }
                copy_str(Line);                
                break;
            }
                
            case 0:
                system("clear");
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