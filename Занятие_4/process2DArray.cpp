#include <iostream>
#include <array>

template<typename T , size_t Rows , size_t Cols , typename Function>
std::array<std::array<T , Cols>, Rows > process2DArray(const std::array<std::array<T , Cols>,Rows>& array , Function func) {
    std::array<std::array<T , Cols>,Rows> new_array {};
    for (size_t i = 0 ; i < Rows ; i++ ) {
        for (size_t j = 0 ; j < Cols ; j++) {
            new_array[i][j] = func(array[i][j]);
        }
    }
    return new_array;
}

template<typename T>
T doubleValue(T x) {
    return 2 * x;
}

int main(){
    std::array<std::array<int, 3>, 2> my_array = {{{1, 2, 3}, {4, 5, 6}}};
    
    auto new_array = process2DArray(my_array,doubleValue<int>);
    
    for (size_t i = 0 ; i < 2 ; i++ ) {
        for (size_t j = 0 ; j < 3 ; j++) {
            std::cout << new_array[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "It's WORK!!!!";
    return 0;
}
