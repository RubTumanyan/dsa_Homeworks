#include <iostream>
#include <string>
#include <vector>

template<typename T,typename Function>
std::vector<T> filterArray(const T* array, size_t size , Function f1) {
    std::vector<T> result;
    for (size_t i = 0 ; i < size ; i++ ) {
        if (f1(array[i])) {
            result.push_back(array[i]);
        }
    }
    return result;
}

int main()
{
    int int_array[] = {1 , 2 , 5 , 7 , 6 , 8 , 12};
    size_t size = sizeof(int_array) / sizeof(int_array[0]);
    auto result_int = filterArray(int_array , size , [](int n){ return n % 2 == 0;});
    std::cout << "these are even numbers :    " << std::endl;
    
    for (int x : result_int) {
        
        std::cout << x << " ";
        
    }
    std::cout <<  std::endl;
    
    double double_array[] = {1.25 , -2.25 , 5.25 , -7.25 , -5.26 , 8.3230 , 12.26526};
    size_t size1 = sizeof(double_array) / sizeof(double_array[0]);
    auto result_double = filterArray(double_array , size1 , [](double n){ return n > 0;});
    std::cout << "these are positive  :    " << std::endl;
    
    for (double x : result_double) {
        
        std::cout << x << " ";
        
    }
    std::cout <<  std::endl;
    
    std::string double_string[] = { "Mkhitaryan",  "Messi" , "Ewu" , "Roony" , "Arteta" , "Ruben"};
    size_t size2 = sizeof(double_string) / sizeof(double_string[0]);
    
    auto result_string = filterArray(double_string , size2 , [](const std::string& n){ return n.size() > 5;});
    std::cout << "these are long names:    " << std::endl;
    
    for (std::string x : result_string) {
        
        std::cout << x << " ";
        
    }
    

    return 0;
}
