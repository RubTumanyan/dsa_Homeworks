#include <iostream>
#include <array>

template <typename Func , typename T>
void applyAndPrint(Func function , T first) {
    T element = function(first);
    std::cout << element << " ";
}


template<typename Func , typename... Args , typename T>
void applyAndPrint (Func function, T first ,Args... arg) {
    
    std::cout << function(first) << " ";
    applyAndPrint(function , arg...);
}

int square(int x) {
    return x * x;
}
int main() {
    applyAndPrint(square, 2, 3, 4, 5);
}
