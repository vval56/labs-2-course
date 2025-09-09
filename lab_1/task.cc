#include "task.h"

using namespace std;

void find_intersection(Array* array1, Array* array2) {
    if (!array1 || !array2 || array1->Size() == 0 || array2->Size() == 0) {
        cout << "Массивы не инициализированы или пусты!" << endl;
        return;
    }

    vector<int> union_set;

    for (int i = 0; i < array1->Size(); i++) {
        int current = array1->Get(i);
        if (find(union_set.begin(), union_set.end(), current) == union_set.end()) {
            union_set.push_back(current);
        }
    }
    
    for (int i = 0; i < array2->Size(); i++) {
        int current = array2->Get(i);
        if (find(union_set.begin(), union_set.end(), current) == union_set.end()) {
            union_set.push_back(current);
        }
    }
    
    cout << "Объединение массивов (" << union_set.size() << " элементов): ";
    for (int num : union_set) {
        cout << num << " ";
    }
    cout << endl;
}

void find_union(Array* array1, Array* array2) {
    if (!array1 || !array2 || array1->Size() == 0 || array2->Size() == 0) {
        cout << "Массивы не инициализированы или пусты!" << endl;
        return;
    }

    int size1 = array1->Size();
    int size2 = array2->Size();

    int* result = new int[size1 + size2];
    int result_size = 0;
    
    for (int i = 0; i < size1; i++) {
        int current = array1->Get(i);
        bool already_exists = false;
        
        for (int j = 0; j < result_size; j++) {
            if (result[j] == current) {
                already_exists = true;
                break;
            }
        }
        
        if (!already_exists) {
            result[result_size++] = current;
        }
    }
    
    for (int i = 0; i < size2; i++) {
        int current = array2->Get(i);
        bool already_exists = false;
        
        for (int j = 0; j < result_size; j++) {
            if (result[j] == current) {
                already_exists = true;
                break;
            }
        }
        
        if (!already_exists) {
            result[result_size++] = current;
        }
    }
    
    cout << "Объединение массивов (" << result_size << " элементов): ";
    for (int i = 0; i < result_size; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    delete[] result;
}