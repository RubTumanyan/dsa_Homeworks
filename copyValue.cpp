#include<iostream>

template<typename T>
T copyValue(const T& value){
    return value;
}
template<typename T>
T* copyValue(T* ptr) {
    
    if(!ptr){
        return nullptr;
    }
    return new T(copyValue(*ptr));
}

int main(){
    int a = 5;
    int b = copyValue(a);
    
    int* ptr = &a;
    int* pt = copyValue(ptr);
    
    std::cout << b << std::endl;
    std::cout << *pt << std::endl;
}
