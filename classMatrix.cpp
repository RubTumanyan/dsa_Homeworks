#include <iostream>
#include <vector>
#include <string>

template <typename T, size_t N, size_t M>
class Matrix{
private:
    T matrix[N][M];
public:
    void set(int row , int col , const T& value) {
        matrix[row][col] = value;
    }
    T get(int row, int col){
        return matrix[row][col];
    }
    void print(){
        for (int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < M ; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
     Matrix<T, N, M> operator+(const Matrix<T, N, M>& other) const {
        Matrix<T, N, M> result;
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < M; j++) {
                result.matrix[i][j] = this->matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }
    
};

int main() {
    Matrix<int, 2, 3> A;
    Matrix<int, 2, 3> B;

    A.set(0, 0, 1);
    A.set(0, 1, 2);
    A.set(0, 2, 3);
    A.set(1, 0, 4);
    A.set(1, 1, 5);
    A.set(1, 2, 6);
    
    B.set(0, 0, 10);
    B.set(0, 1, 20);
    B.set(0, 2, 30);
    B.set(1, 0, 40);
    B.set(1, 1, 50);
    B.set(1, 2, 60);

    std::cout << "Matrix A:\n";
    A.print();

    std::cout << "Matrix B:\n";
    B.print();

    Matrix<int, 2, 3> C = A + B;
    std::cout << "Matrix C = A + B:\n";
    C.print();

    return 0;
}
