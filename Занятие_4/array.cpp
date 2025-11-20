#include <iostream>
#include <array>


int main()
{
    std::array<int,5> number;
    int num = 1;
    for(int i = 0 ; i < number.size() ; i++) {
        number[i] = num++;
    }
    
    for (int x : number) {
        std::cout << x << " ";
    }
    return 0;
}
