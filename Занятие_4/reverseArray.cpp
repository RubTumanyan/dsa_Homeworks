#include <iostream>
#include <array>
#include <string>

template<typename T,int N>
void reverseArray(std::array<T,N>& numbers) {
    for (int i = 0 ; i < numbers.size()/2 ; i++) {
         T num = numbers[i];
         numbers[i] = numbers[numbers.size() - 1 - i];
         numbers[numbers.size()-1-i] = num;
    } return;
}

int main()
{        
    std::array<int,10> array = {1 , 2 , 5 , 4 , 5 , 4 , 2 , 6 , 3 , 45};
    std::array<std::string,3> array1 = {"KAKA" , "Carlos" , "miki"};
    
    
    reverseArray<int , 10>(array);
    for (int x: array) {
        std::cout << x << " ";
     }
    std::cout << std::endl;
    reverseArray<std::string , 3>(array1);
    for (std::string str: array1) {
         std::cout << str << " ";
     }
    return 0;
}
