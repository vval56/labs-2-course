#include <vector>
#include <limits>
#include "../headers/input_array.h"

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

void hand_input(Array*& array1, Array*& array2) {
    vector<int> buff_array1;
    vector<int> buff_array2;
    int number;
    
    cout << "Ввод первого массива" << endl;
    cout << "Вводите числа. Для завершения ввода нажмите Enter дважды:\n";
    
    while (true) {
        number = check_int();
        buff_array1.push_back(number);

        if (cin.peek() == '\n') {
            cin.get(); 
            break;
        }
    }
    
    array1 = new Array(buff_array1.size(), buff_array1.data());
    
    cout << "\nВвод второго массива" << endl;
    cout << "Вводите числа. Для завершения ввода нажмите Enter дважды:\n";
    
    while (true) {
        number = check_int();
        buff_array2.push_back(number);

        if (cin.peek() == '\n') {
            cin.get();
            break;
        }
    }
    
    array2 = new Array(buff_array2.size(), buff_array2.data());
}

void random_input(Array*& array1, Array*& array2) {
    cout << "Введите размер первого массива" << endl;
    int size1 = check_int();
    array1 = new Array(size1, true);

    cout << "Введите размер первого массива" << endl;
    int size2 = check_int();
    array2 = new Array(size2, true);
}

void show_arrays(Array*& array1, Array*& array2) {
    cout << "Ваш первый массив:" << endl;
    for(int i = 0; i < array1->Size(); i++){
        cout << array1->Get(i) << ", " ;
    }

    cout << endl << "Ваш второй массив:" << endl;
    for(int i = 0; i < array2->Size(); i++){
        cout << array2->Get(i) << ", " ;
    }
}

void press_enter_to_continue() {
    cout << endl << "Нажмите Enter для продолжения...";
    getchar();
}

void show_menu(){
    cout << "1 - Ввести вручную массивы" << endl 
         << "2 - Ввести случайные массивы" << endl
         << "3 - Посмотреть массивы" << endl
         << "4 - Пересечение массивов" << endl
         << "5 - Обьединение массивов" << endl 
         << "0 - Выход" << endl;
}

[[noreturn]] void input(Array*& array1, Array*& array2) {
    int choice = -1;

    while(true) {
        system("clear");
        show_menu();
        choice = check_int();

        switch (choice) {
        case 1:
            system("clear");
            hand_input(array1, array2);
            press_enter_to_continue();
            break;
            
        case 2:
            system("clear");
            random_input(array1, array2);
            press_enter_to_continue();
            break;
            
        case 3:
            system("clear");
            show_arrays(array1, array2);
            press_enter_to_continue();
            break;
            
        case 4:
            system("clear");
            show_arrays(array1, array2);
            find_intersection(array1, array2);
            press_enter_to_continue();
            break;
            
        case 5:
            system("clear");
            show_arrays(array1, array2);
            find_union(array1, array2);
            press_enter_to_continue();
            break;

        case 0:
            system("clear");
            delete array1; 
            delete array2;
            exit(0);
        
        default:
            cout << "Введите число от 0 до 5" << endl;
            press_enter_to_continue();
        }
    }
}