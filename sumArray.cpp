#include <iostream>


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
    
    double array2[5] = {4.52 , 5.25 , 2.26 ,3.456};
    std::cout << sumArray(array2 , 5);
    
    std::cout << std::endl;
    std::string array3[3] = {"hello" , "Miki" , "Karen"};
    
    std::string result = sumArray(array3 , 3);
    std::cout << result;
    std::cout << "\n" << "its work"<< std::endl;
    
    
    
}
