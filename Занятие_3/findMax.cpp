#include <iostream>

template<typename T>
T findMax(T number) {
    return number;
}

template<typename T,typename... Args>
auto findMax(T first ,Args... arg) {
    auto max_el = findMax(arg...);
    return (first > max_el) ? first : max_el;
}


int main()
{   
    std::cout << "The MAX is: ";
    std::cout << findMax(1.5 , 10 , 25 , 25.5465 ) << std::endl;
    std::cout << "The MAX is: ";
    std::cout << findMax(3 , 25.45465f , 25 , 848);
    
    return 0;
}
