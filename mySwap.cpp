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
    int a = 10;
    int b = 225;
    mySwap(a,b);

}
