#include "../headers/algorithm.h"
#include <vector>

Queue::Iterator Algorithm::find(Queue::Iterator start, Queue::Iterator end, const int& value){
    auto it = start;
    while (it != end) {
        if (*it == value) {
            return it;
        }
        ++it;
    }
    return end;
}

void Algorithm::sort(Queue queue) {
    if (queue.empty()) return;
        
    std::vector<int> temp;
    auto it = queue.begin();
    while (it != queue.end()) {
        temp.push_back(*it);
        ++it;
    }
        
    std::sort(temp.begin(), temp.end());
        
    while (!queue.empty()) {
        queue.pop();
    }
        
    for (const auto& item : temp) {
        queue.push(item);
    }
}
