#include <bits/stdc++.h>



template<typename T>

bool isOdd(const T& number) 
{   
    bool result =number;
    return result & 1 ;
}

template<typename T>

bool IsShort(const T& string) {
    if( string.size <= 5  ){
        return true;
    }
    return false;
}






template<typename T>
std::vector<T> filterArray(T* array , int size) {
    std::vector<T> array1;
    for (int i = 0 ; i < size ; i++) {
        if(isOdd(array)) {
            array1.push_back(array[i]);
        }
    }
    return array1;
} 

int main() {
    
     int array[] = {5,4,3,5,2};
     std::vector<int> numbers= filterArray( array , 5 );
     for(int i = 0 ; i < numbers.size() ; i++ ) {
         std::cout << numbers[i] << " ";
     }
     std::cout << std::endl;
     double array1[] = {5.22 , 4.00 , 3.11 , 5.111 , 2.33};
     std::vector<double> numbers1 = filterArray( array1 , 5 );
     for(int i = 0 ; i < numbers1.size() ; i++ ) {
         std::cout << numbers1[i] << " ";
     }
     std::cout << std::endl;
     std::string array3[] = { "mika" , "karen" , "sa"};
     std::vector<std::string> strings = filterArray(array3 , 3);
     for (int i = 0 ; i < strings.size() ; i++ ) {
         std::cout << strings[i] << " ";
     }
     std::cout << std::endl;
     
     
   
    
    
    
}
