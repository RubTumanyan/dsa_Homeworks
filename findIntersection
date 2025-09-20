#include <iostream>
#include <vector>
std::vector<int> findIntersection(std::vector<int>& num, std::vector<int>& number) {
    std::vector<int> result;
    bool found = false;
    for (int i = 0 ; i < num.size() ; i++) {
        for (int j = 0 ; j < number.size() ; j++) {
            if (num[i] == num[j]) {
                found = true;
            }
        }
        bool count = false;
        if (found) {
            for (int k = 0 ; k < result.size() ; k++) {
                if (num[i] == result[k]) {
                    count = true;
                }
            }
            if (!count) {
                result.push_back(num[i]);
            }
        }
    }
    return result;
}
int main()
{
    std::vector<int> num {4 , 5 , 2 , 5};
    std::vector<int> num1 { 4 , 5 , 5 , 5 , 5 };
    std::vector<int> vec = findIntersection(num,num1);
    for (int &x : vec) {
        std::cout << x << " ";
    }
    return 0;
}
