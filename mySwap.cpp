#include <bits/stdc++.h>

template<typename T>
void mySwap(T el1 , T el2) {
    
    T el3 = el1;
    el1 = el2;
    el2 = el3;
    std::cout << "after swap   " << el1 << " " << el2;
}


int main() {
    
    std::string s1 = "hello";
    std::string s2 = "Byeeee";
    mySwap(s1,s2);
    std::cout << std::endl;
    
    int num_int = 10;
    int num1_int = 225;
    mySwap(num_int , num1_int);
    std::cout << std::endl;
    double num_float = 4.25;
    double num1_float = 4.256;
    mySwap(num_float , num1_float);
}
