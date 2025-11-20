#include <iostream>
#include <array>
#include <string>

template<typename T,int N>
bool compareArray(std::array<T,N>& numbers , std::array<T,N>& numbers1) {
    for (int i = 0 ; i < numbers.size() ; i++) {
         if(numbers[i] != numbers1[i]) {
             return false;
         }
    } return true;
}

int main()
{        
    std::array<int,10> array = {1 , 2 , 5 , 4 , 5 , 4 , 2 , 6 , 3 , 45};
    std::array<int,10> array1 = {1 , 2 , 5 , 4 , 5 , 4 , 2 , 6 , 3 , 45};
    
    std::array<int,10> array2 = {1 , 2 , 5 , 3 , 5 , 4 , 2 , 6 , 3 , 45};
    std::array<int,10> array3 = {1 , 2 , 5 , 5 , 7 , 8 , 15151515 , 6 , 3 , 45};
    
    if(compareArray<int,10>(array,array1)) {
        std::cout << "true";
    }else{
        std::cout << "false";
    }
    std::cout << std::endl;
    
    if(compareArray<int,10>(array2,array3)) {
        std::cout << "true";
    }else{
        std::cout << "false";
    }
    std::cout << std::endl;
    
    return 0;
}
