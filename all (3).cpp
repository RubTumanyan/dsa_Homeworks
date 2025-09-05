#include <bits/stdc++.h>



template<typename T>
T sumArray(T* array , int size) {
    T sum{};
    for(int i = 0 ; i < size ; i++) {
        sum += array[i];
    }
    return sum;
}

int main() {
    
    int array1[5] = {4,5,2,3,6};
    std::cout << sumArray(array1 , 5);
    std::cout << std::endl;
    std::string array2[3] = {"hello" , "Miki" , "Karen"};
    std::string result = sumArray(array2 , 3);
    std::cout << result;
    std::cout << "/n" << std::cout << "its work"<< std::endl;
    
    
    
}
