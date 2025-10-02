#include "../headers/menu.h"

#include <cctype>
#include <sstream>
#include <limits>

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

void print_menu(){
    cout << "Меню наследования класса фигур\n"
         << "1 - Создать первую фигуру\n"
         << "2 - Создать вторую фигуру\n"
         << "3 - Посмотреть пересечение\n"
         << "0 - Выход\n";
}

Shape* create_figure(int choice){
    switch (choice){
    case 1:
        return new Circle();
    case 2:
        return new Square();
    case 3:
        return new Triangle();
    default:
        return nullptr;
    }
}

bool intersect_2_shapes(const Shape * shape1, const Shape * shape2){
    if (shape1 == nullptr || shape2 == nullptr) {
        cout << "Ошибка: фигуры не созданы\n";
        return false;
    }
    return shape2->intersect_with(shape1);
}

void choose_figure(Shape *& Shape){
    cout << "Выберите фигуру:\n"
         << "1 - Круг\n"
         << "2 - Квадрат\n"
         << "3 - Треугольник\n";

    int choice = 0;

    do{
        choice = check_int();
        switch (choice){
        case 1:
            Shape = create_figure(1);
            cout << "Создан круг\n";
            break;
        case 2:
            Shape = create_figure(2);
            cout << "Создан квадрат\n";
            break;
        case 3:
            Shape = create_figure(3);
            cout << "Создан треугольник\n";
            break;
        
        default:
            cout << "Невернно введеное число\n";
        }
    }while(choice < 1 || choice > 3);
}

void menu(Shape *& shape1, Shape *& shape2){
    int choice = 0;

    do{
        system("clear");
        print_menu();
        choice = check_int();

        switch (choice){
        case 1:
            system("clear");
            choose_figure(shape1);
            break;
        case 2:
            system("clear");
            choose_figure(shape2);
            break;
        case 3:
            system("clear");

            if(shape1 == nullptr || shape2 == nullptr){
                cout << "Определены не все фигуры\n";
                break;
            }

            intersect_2_shapes(shape1, shape2);
            break;
            
        case 0:
            system("clear");
                cout << "Выход из программы...\n";
                break;
        
        default:
            cout << "Неверный выбор! Попробуйте снова.\n";
        }

        if (choice != 0) {
            cout << "\nНажмите Enter для продолжения...";
            cin.ignore();
            cin.get();
        }

    }while(choice != 0);

    delete shape1;
    delete shape2;
    shape1 = nullptr;
    shape2 = nullptr;
}