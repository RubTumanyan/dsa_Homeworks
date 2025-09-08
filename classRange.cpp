#include <iostream>
#include <vector>
#include <string>

template<typename T>
class Range{
private:
    T start;
    T end;
public:
    Range(T first , T second ) : start(first), end(second){
        if (end < start) {
            throw std::invalid_argument("end must be higher than start");
        }
    }
    bool contains(const T& value) {
           return value >= start && value <= end;
    }
    
    T length() const {
        return end - start;
    }
    
    void print() const {
        std::cout << "[" << start << " , " << end<< "]" << std::endl;
    }
};

int main() {
    
    Range<int> p1(1,10);
    std::cout << p1.length() << std::endl;
    std::cout << "p1 contains 8?   " << (p1.contains(8)?"Yes":"No")<< std::endl;
    
    Range<double> p2(1.255,2.44654);
    std::cout << p2.length() << std::endl;
    std::cout << "p2 contains 2.2146?    " << (p1.contains(2.2146)?"Yes":"No")<< std::endl;
    
    Range<int> p3('a','s');
    std::cout << p3.length() << std::endl;
    std::cout << "p3 contains 8?   " << (p1.contains('s')?"Yes":"No")<< std::endl;
}
