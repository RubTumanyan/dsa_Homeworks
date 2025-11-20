#include <iostream>
#include <array>
template<int N>
int countEven(std::array<int,N>& numbers) {
    int count = 0;
    for (int i = 0 ; i < numbers.size() ; i++) {
        if (numbers[i] % 2 == 0 ) {
            count++;
        }
    } 
    return count;
    }

int main()
{
    
    std::array<int, 6> arr = {1, 2, 3, 4, 5, 6};
    int count = countEven<6>(arr);
    std::cout << count;
    return 0;
}
