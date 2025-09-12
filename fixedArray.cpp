#include <iostream>
#include <vector>
#include <string>

template <typename T,size_t N>
class fixedArray{
private:
    T array[N];
public:
    void setElement(int index , const T& value) {
        array[index] = value;
    }
    T get(int index) {
        return array[index];
    }
    size_t size(){
        return N;
    }
};

int main(){
    fixedArray<int,5> array_int;
    for (size_t i = 0 ; i < array_int.size() ; i++) {
        array_int.setElement(i,i*2);
    }
    for (size_t i = 0 ; i < array_int.size() ; i++ ) {
        array_int.get(i);
        std::cout << " ";
    }
    std::cout << std::endl;
    
    fixedArray<double,5> array_double;
    for (size_t i = 0 ; i < array_double.size() ; i++) {
        array_double.setElement(i,i*2.2555);
    }
    for (size_t i = 0 ; i < array_double.size() ; i++ ) {
        array_double.get(i);
        std::cout << " ";
    }
    std::cout << std::endl;
    
    fixedArray<std::string,5> array_string;
    array_string.setElement(0,"Haren");
    array_string.setElement(1,"Lusine");
    array_string.setElement(2,"Miqayel");
    array_string.setElement(3,"Karii");
    array_string.setElement(4,"Lusiiii");
    }
    for (size_t i = 0 ; i < array_string.size() ; i++ ) {
        array_string.get(i);
        std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}
