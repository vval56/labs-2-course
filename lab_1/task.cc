#include "task.h"

void find_intersection(Array* array1, Array* array2) {
    if (!array1 || !array2 || array1->Size() == 0 || array2->Size() == 0) {
        cout << "Массивы не инициализированы или пусты!" << endl;
        return;
    }

    int* data1 = const_cast<int*>(array1->GetData());
    int* data2 = const_cast<int*>(array2->GetData());
    int size1 = array1->Size();
    int size2 = array2->Size();
    
    sort(data1, data1 + size1);
    sort(data2, data2 + size2);
    
    vector<int> intersection;
    int i = 0, j = 0;
    
    while (i < size1 && j < size2) {
        if (data1[i] < data2[j]) {
            i++;
        } else if (data1[i] > data2[j]) {
            j++;
        } else {
            if (intersection.empty() || intersection.back() != data1[i]) {
                intersection.push_back(data1[i]);
            }
            i++;
            j++;
        }
    }
    
    cout << "Пересечение массивов (" << intersection.size() << " элементов): ";
    for (int num : intersection) {
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