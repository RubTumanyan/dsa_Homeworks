#include <iostream>
#include <string>

template <typename T , typename T1 >

class Pair{
private:

    T first;
    T1 second;
    
public:
    
    Pair(T fist_v , T1 second_v ): first(fist_v) , second(second_v){}
    
    void printElements() {
        std::cout << first << " " << second << std::endl;
    }
};

int main(){
    Pair p1(4,"Kar");
    p1.printElements();
    
    Pair p2("sa" , 4.456456);
    p2.printElements();
}
