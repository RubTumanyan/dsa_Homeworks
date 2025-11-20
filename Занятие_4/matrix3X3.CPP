#include <iostream>
#include <array>
#include <algorithm>

class Matrix3x3{
private:
    std::array<std::array<int, 3>, 3> matrix;
public:
    Matrix3x3(int a , int b , int c , int d ,int e , int l ,int k , int y , int h){
        matrix = {a,b,c,d,e,l,k,y,h};
    }
    int getElement(int row,int col){
        return matrix[row][col];
    }
    void setElement(int row,int col,int value){
        matrix[row][col] = value;
    }
    void transpose(){
        for (int i = 0 ; i < 3 ; i++ ){
            for (int j = i + 1 ; j < 3 ; j++){
                int element = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = element;
            }
        }
    }
    void print(){
        for (int i = 0 ; i < 3; i++ ) {
            for (int j = 0 ; j < 3 ; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};
int main()
{  
    Matrix3x3 matrix(1, 2, 3, 4, 5, 6, 7, 8, 9);
    matrix.print();
    std::cout << "\n";
    matrix.transpose();
    matrix.print();
    return 0;
}
