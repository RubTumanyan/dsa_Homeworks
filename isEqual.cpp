#include <iostream>
#include <cstring>

template <typename T>
bool isEqual(const T& a ,const T& b) {
    if (a == b){
        return true;
    }else{
        return false;
    }
}

bool isEqual( const char* a , const char* b) {
    
    int result = strcmp(a,b);
    if (result == 0){
        return true;
    }else{
        return false;
    }
}
int main(){
    
    std::cout << (isEqual(5 , 5)?"Yes\n":"No\n");
    std::cout << (isEqual(5.454 , 5.565)?"Yes\n":"No\n");
    std::cout << (isEqual(5.1121 , 5.55)?"Yes\n":"No\n");
    std::cout << (isEqual("Karen" , "Lilit" )?"Yes\n":"No\n");
    

    
    return 0;
}
