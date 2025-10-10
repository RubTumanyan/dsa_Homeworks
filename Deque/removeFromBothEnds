#include <iostream>
#include <deque>

void removeFromBothEnds(std::deque<int> &deq , int K) {

    int maxRevols = deq.size()/2;
    K = (K > maxRevols ? maxRevols : K);
    for(int i = 0 ; i < K ;i++) {
        deq.pop_front();
        deq.pop_back();
        std::cout << "size is " << deq.size() << std::endl;
    }
}

int main() {
     std::deque<int> deq={1,2,3,4,5,6,7,8,9,10};
     removeFromBothEnds(deq,2);
     for (int &x : deq) {
     std::cout << x << " ";
     }
     return 0;
}
