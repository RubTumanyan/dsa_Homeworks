#include <iostream>
#include <string>
#include <vector>

template<typename T>
int linerSearch(std::vector<T>& array, const T& target) {
    for (size_t i = 0 ; i < array.size() ; i++ ) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::vector<int> array = {1 , 2 , 5 , 3 , 5};
    int index = linerSearch(array , 2);
    std::cout << std::endl;
    std::cout << "the element 2 in the index: " << index << std::endl; 
    
    std::vector<double> array1 = {1.2525 , 2.45465 , 5.41564564 , 3.45456 , 5.4547};
    int index1 = linerSearch(array1 , 2.45465);
    std::cout << std::endl;
    std::cout << "The element 2.45465 in the index; " << index1 << std::endl;
    
    std::vector<std::string> array2 = {"Karen" , "Lilit" , "Armenak" , "Karine" , "Albert"};
    int index2 = linerSearch(array2,std::string("Karen"));
    std::cout << std::endl;
    std::cout << "The name Karen in the index: " << index2 << std::endl;
    return 0;
}
