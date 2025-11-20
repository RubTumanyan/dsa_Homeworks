#include <iostream>
#include <utility> 

void print(int& x) { std::cout << "lvalue: " << x << "\n"; }
void print(int&& x) { std::cout << "rvalue: " << x << "\n"; }


template<typename T>
void wrapper(T&& value) { 
    print(std::forward<T>(value));  

    
}

int main() {
    
    int a = 25;
    wrapper(a);     
    wrapper(26); 
}
