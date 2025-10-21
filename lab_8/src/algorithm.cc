#include "../headers/algorithm.h"
#include <vector>

template<typename t>
Queue<t>::Iterator Algorithm<t>::find(Queue<t>::Iterator start, Queue<t>::Iterator end, const t& value){
    auto it = start;
    while (it != end) {
        if (*it == value) {
            return it;
        }
        ++it;
    }
    return end;
}

template<typename t>
int Algorithm<t>::partition(t* arr, int low, int high) {
    t pivot = arr[high]; 
    int i = (low - 1);     
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;  
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template<typename t>
void Algorithm<t>::sort(Queue<t>& queue) {
    if (queue.empty()) return;
    
    int count = 0;
    auto it = queue.begin();
    while (it != queue.end()) {
        count++;
        ++it;
    }
    
    auto temp = new t[count];
    
    it = queue.begin();
    for (int i = 0; i < count; i++) {
        temp[i] = *it;
        ++it;
    }
    
    if (count > 0) {
        quickSort(temp, 0, count - 1);
    }
    
    while (!queue.empty()) {
        queue.pop();
    }

    for (int i = 0; i < count; i++) {
        queue.push(temp[i]);
    }
    
    delete[] temp;
}

template<typename t>
void Algorithm<t>::swap(t& a, t& b) {
    t temp = a;
    a = b;
    b = temp;
}

template<typename t>
void Algorithm<t>::quickSort(t* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
    
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

template class Algorithm<int>;
template class Algorithm<double>;
template class Algorithm<char>;
