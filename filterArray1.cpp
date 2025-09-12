#include <iostream>
#include <array>

void filterArray(std::array<int,7>& array1 , int number) {
    for (int i = 0 ; i < array1.size() ; i++) {
        array1[i] = number;
    }
}

int main()
{
    std::array<int,7> numbers;
    int num = 1;
    for(int i = 0 ; i < numbers.size() ; i++) {
        numbers[i] = num++;
    }
    
    filterArray(numbers,45);
    for (int x : numbers) {
        std::cout << x << ' ';
    }
    return 0;
}
