#include <iostream>

template<typename T>
T sum(T number) {
    return number;
}

template<typename T,typename... Args>
auto sum(T num , Args... arg) {
    return num + sum(arg...);

}
int main()
{   std::cout << "The sum is: ";
    std::cout << sum(1.5 , 10 , 25 , 25.5465 );

    return 0;
}
