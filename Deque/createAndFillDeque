#include <iostream>
#include <deque>

void createAndFillDeque(int n) {
    std::deque<int> numbers{};
    for (int i = 1 ; i <=n ; i+=2) {
        numbers.push_back(i);
    }
    for (int i = 2 ; i <=n ; i += 2) {
        numbers.push_front(i);
    }
    for (int &x : numbers) {
        std::cout << x << " ";
    }
}
int main() {
    createAndFillDeque(10);
    return 0;
}
