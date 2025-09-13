#include<array>
#include <iostream>
template<int N>
std::array<int,256> countFrequency(std::array<char,N>& arr) {
    std::array<int,256> freq{};
    for (char x : arr) {
        unsigned char k = static_cast<unsigned char>(x);
        freq[k]++;
    }
    return freq;
}
int main()
{
    std::array<char, 5> text = {'h', 'e', 'l', 'l', 'o'};
    auto freq = countFrequency<5>(text);
    
        std::cout << freq['h'] << std::endl;
        std::cout << freq['e'] << std::endl;
        std::cout << freq['l'] << std::endl;
        std::cout << freq['o'] << std::endl;
        std::cout << freq['m'] << std::endl;
    
    return 0;
}
