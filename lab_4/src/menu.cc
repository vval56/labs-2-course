#include "../headers/menu.h"

#include <cctype>
#include <sstream>
#include <limits>

using namespace std;

double check_double() {
    double number;
    string input;
    
    while (true) {
    getline(cin, input);
    
    if (stringstream ss(input); ss >> number && ss.eof()) {
        return number;
    }
    cout << "Ошибка. Введите число: ";
}
}

int check_int() {
    int number;
    string input;
    
    while (true) {
    getline(cin, input);
    
    if (stringstream ss(input); ss >> number && ss.eof()) {
        return number;
    }
    cout << "Ошибка. Введите число: ";
    }
}

void print_menu(){
    cout << "Меню наследования класса фигур\n"
         << "1 - Создать фигуру\n"
         << "2 - Посчитать площади фигур\n"
         << "3 - Посмотреть фигуры\n"
         << "0 - Выход\n";
}

Shape* create_figure(int choice, double *params){
    switch (choice){
    case 1: return new Circle(params);
    case 2: return new Rectangle(params);
    case 3: return new Triangle(params);
    case 4: return new Trapezoid(params);
    default: return nullptr;
    }
}

void choose_figure(Shape *&shape){
    cout << "Выберите фигуру:\n"
         << "1 - Круг\n"
         << "2 - Прямоугольник\n"
         << "3 - Прямоугольный треугольник\n"
         << "4 - Трапеция\n";

    int choice = 0;
    double *params = nullptr;

    do {
        choice = check_int();
        switch (choice){
        case 1:
            cout << "Введите радиус: ";
            params = new double[1];
            params[0] = check_double();
            shape = create_figure(1, params);
            cout << "Создан круг c радиусом " << params[0] << "\n";
            delete[] params;
            break;
        case 2:
            cout << "Введите стороны: ";
            params = new double[2];
            for(int i = 0; i < 2; i++) params[i] = check_double();
            shape = create_figure(2, params);
            cout << "Создан прямоугольник со сторонами " << params[0] << ", " << params[1] << "\n";
            delete[] params;
            break;
        case 3:
            cout << "Введите катеты: ";
            params = new double[2];
            for(int i = 0; i < 2; i++) params[i] = check_double();
            shape = create_figure(3, params);
            cout << "Создан прямоугольный треугольник с катетами " << params[0] << ", " << params[1] << "\n";
            delete[] params;
            break;
        case 4:
            cout << "Введите основания и высоту: ";
            params = new double[3];
            for(int i = 0; i < 3; i++) params[i] = check_double();
            shape = create_figure(4, params);
            cout << "Создана трапеция со сторонами " << params[0] << ", " << params[1] << " и высотой " << params[2] << "\n";
            delete[] params;
            break;
        default:
            cout << "Неверный ввод! Попробуйте снова: ";
        }
    } while(choice < 1 || choice > 4);
}

void menu(){
    int choice = 0;
    Shape **Shapes = nullptr; 
    int size_shapes = 0;

    do {
        system("clear");
        print_menu();
        choice = check_int();

        switch (choice){
        case 1: {
            system("clear");

            Shape* newShape = nullptr;
            choose_figure(newShape);
            auto **newArr = new Shape*[size_shapes + 1];
            for (int i = 0; i < size_shapes; i++) {
                newArr[i] = Shapes[i];
            }
            newArr[size_shapes] = newShape;
            delete[] Shapes;
            Shapes = newArr;
            size_shapes++;

            break;
        }
        case 2:
            system("clear");
            if(size_shapes == 0) {
                cout << "Фигур нет. Сначала создайте фигуру.\n";
                break;
            }
            for(int i = 0; i < size_shapes; i++)
                cout << "Площадь фигуры '" << Shapes[i]->Name() << "' : " << Shapes[i]->Square() << "\n";
            break;
        
        case 3:
            system("clear");
            if(size_shapes == 0) {
                cout << "Фигур нет. Сначала создайте фигуру.\n";
                break;
            }

            cout << "Список всех фигур\n";
            for(int i = 0; i < size_shapes; i++){
                cout << "Фигура " << Shapes[i]->Name() << " ";
                Shapes[i]->Parametrs();
            }
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while(choice != 0);

    for(int i = 0; i < size_shapes; i++)
        delete Shapes[i];
    delete[] Shapes;
}
