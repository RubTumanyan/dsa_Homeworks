#include <iostream>
#include <array>

template <typename T,int N,int M>
std::array<T,M> copySubArray(std::array<T,N>& array , int index, int size) {
    std::array<T,M> new_array {0};
    for (int i = 0 ; i < M ; i++) {
        new_array[i] = array.at(i + index);
    }
    return new_array;
}
int main()
{  
    std::array<int,5> numbers{1 , 5 , 2 ,1 , 5};
    std::cout << "Original:\a";
    for (int x : numbers) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "Copy:\a ";
    
    auto new_array = copySubArray<int,5,2>(numbers ,2 ,2);
    for (int x : new_array) {
        std::cout << x << " ";
    }

    return 0;
}
