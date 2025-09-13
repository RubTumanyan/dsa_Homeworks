#include <iostream>
#include <array>

class Logger{
private:
    int count;
public:
    Logger(int x):count(x){}
    template<typename T>
    void print(T first) {
        for (int i = 0 ; i < count ; i++) {
            std::cout << " ";
        }
        std::cout << first << std::endl;
    }
    template<typename T,typename... Args>
    void print(T first ,Args... arg) {
        for (int i = 0; i < count; i++) {
            std::cout << " ";
        }
        std::cout << first << std::endl;
        
        print(arg...);
    }
};
int main()
{
    Logger logger(4);  
    logger.print("Hello", 42, 3.14, 'A');

    return 0;
}
