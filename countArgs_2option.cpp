#include <iostream>

template<typename... Args > 
size_t count(Args... arg) {
    return sizeof...(arg);
}


int main()
{   
    std::cout << "The size is: ";
    std::cout << count(1.5 , 10 , 25 , 25.5465 ) << std::endl;
    std::cout << "The size is: ";
    std::cout << count(3 , 25.45465f , "hshc" , "M" ,848);
    
    return 0;
}
