#include <iostream>

template<typename T>
std::string makeSentence(T string) {
    return std::string(string) + ".";
}

template<typename T,typename... Args>
std::string makeSentence(T first , Args...arg) {
    return std::string(first) + " " + makeSentence(arg...);
}



int main()
{   
    std::cout << makeSentence("Miki" , "in" , "our" , "national" , "team");
    
    return 0;
}
