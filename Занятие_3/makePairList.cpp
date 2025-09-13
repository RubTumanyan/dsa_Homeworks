#include <iostream>
#include <utility> 

template<typename T1, typename T2>
auto makePairList(T1 a, T2 b) {
    return std::pair<T1, T2>(a, b);
}

template<typename T1, typename T2, typename... Rest>
auto makePairList(T1 a, T2 b, Rest... rest) {
    return std::pair<T1, decltype(makePairList(b, rest...))>(a,makePairList(b, rest...));
}

int main() {
    auto pair1 = makePairList(5, 'c');
    auto pair2 = makePairList(5, 'c', 4.32);
    auto pair3 = makePairList(1, 2, 3, 4);

    std::cout << pair1.first << ", " << pair1.second << "\n";                   
    std::cout << pair2.first << ", " << pair2.second.first << ", " << pair2.second.second << "\n"; 
    std::cout << pair3.first << ", " << pair3.second.first << ", "
              << pair3.second.second.first << ", " << pair3.second.second.second << "\n";  
}

