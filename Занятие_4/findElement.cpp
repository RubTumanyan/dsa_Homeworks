#include <iostream>
#include <array>
#include <string>
template<typename T,int N>
int findElement(std::array<T,N>& numbers , T num) {
    for (int i = 0 ; i < numbers.size() ; i++) {
        if(numbers[i] == num) {
            return i;
        }
    } return -1;
}

int main()
{
    std::array<int,10> array = {1 , 2 , 5 , 4 , 5 , 4 , 2 , 6 , 3 , 45};
    std::array<std::string,3> array1 = {"KAKA" , "Carlos" , "miki"};
    
    
    std::cout << findElement<int , 10>(array,5);
    std::cout << std::endl;
    std::cout << findElement<std::string , 3>(array1,"klsak");
    return 0;
}
