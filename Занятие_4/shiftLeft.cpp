#include <iostream>
#include <array>
#include <algorithm>


template<typename T,int N>
void shiftLeft( std::array<T, N>& number , int left ) {
    for ( int i = 0 ; i < left ; i++ ) {
        int element = number[0];
        for (int j = 0 ; j < number.size() ; j++) {
            number[j] = number[j+1];
        }
        number[number.size() - 1 ] = element;
    }

}
int main()
{  
    std::array<int,8> number{4 , 3 , 5 , 4 , 5 ,6 , 3 ,4};
    shiftLeft<int , 8>(number , 2);
    for (int x: number){
        std::cout << x << " ";
    }
    
    return 0;
}
