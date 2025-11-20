#include <iostream>
#include <string>

template <typename T>
void printValue(const T& value) {
    std::cout << value << std::endl;
}

template <>
void printValue<bool>(const bool& value) {
    std::cout << (value ? "true" : "false") << std::endl;
}

template <>
void printValue<char*>(char* const& value) {
    std::cout << "[\"" << value << "\"]" << std::endl;
}
int main(){
    
    printValue(42);         
    printValue(3.14);        
    printValue(true);       
    printValue(false);       
    printValue("Hello");
    
    return 0;
}
