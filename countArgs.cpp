#include <iostream>

template<typename T>
size_t count(T number) {
    return 1;
}

template<typename T,typename... Args>
auto count(T first ,Args... arg) {
    return 1 + count(arg...);
}


int main()
{   
    std::cout << "The size is: ";
    std::cout << count(1.5 , 10 , 25 , 25.5465 ) << std::endl;
    std::cout << "The size is: ";
    std::cout << count(3 , 25.45465f , "hshc" , "M" ,848);
    
    return 0;
}
