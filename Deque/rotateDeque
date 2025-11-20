#include <deque>
#include <iostream>
#include <deque>

template<typename T>
void rotateDeque(std::deque<T>& deq , int K) {
    if (K > 0) {
        for (int i = 0 ; i < K ; i++) {
            T tmp = deq.back();
            deq.pop_back();
            deq.push_front(tmp);
        }
    }
    else if (K < 0) {
        for (int i = K ; i != 0 ; i++) {
            T tmp = deq.front();
            deq.pop_front();
            deq.push_back(tmp);
        }
    }
}
int main() {
    std::deque<int> deq {4,5,2,6,5,8,5,6,9,5,6,5,8};
    rotateDeque(deq, 4);
    for (int& x : deq) {
        std::cout << x << ' ';
        
    }
    return 0;
}
