#include <unordered_set>
#include "../headers/task.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;

void find_intersection(const Array* array1, const Array* array2) {
    if (!array1 || !array2 || array1->Size() == 0 || array2->Size() == 0) {
        cout << "Массивы не инициализированы или пусты!" << endl;
        return;
    }

    vector<int> arr1; vector<int> arr2; vector<int> intersection;

    for(int i = 0; i < array1->Size(); i++){
        arr1.push_back(array1->Get(i));
    }

    for(int i = 0; i < array2->Size(); i++){
        arr2.push_back(array2->Get(i));
    }

    ranges::sort(arr1);
    ranges::sort(arr2);

    int i = 0;
    int j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            if (intersection.empty() || intersection.back() != arr1[i]) {
                intersection.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    cout << "Пересечение составялет " << intersection.size() << "элементов." << endl;
    if(!intersection.empty()){
        cout << "{";
        for (int num : intersection)
            cout << num << " ";
        
        cout << "}" << endl;
    }
}

void find_union(const Array* array1, const Array* array2) {
    if (!array1 || !array2 || array1->Size() == 0 || array2->Size() == 0) {
        cout << "Массивы не инициализированы или пусты!" << endl;
        return;
    }

    vector<int> arr1; vector<int> arr2; vector<int> intersection;

    for(int i = 0; i < array1->Size(); i++){
        arr1.push_back(array1->Get(i));
    }

    for(int i = 0; i < array2->Size(); i++){
        arr2.push_back(array2->Get(i));
    }

    unordered_set<int> union_set;
    
    for (int num : arr1) {
        union_set.insert(num);
    }
    
    for (int num : arr2) {
        union_set.insert(num);
    }
    
    cout << "Объединение (" << union_set.size() << " элементов): ";
    for (int num : union_set) {
        cout << num << " ";
    }
    cout << endl;
}