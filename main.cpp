#include <deque>
#include <iostream>

template<typename T>
class CircularDeque {
private:
    T* buffer;
    int capacity;
    int size;
    int front;
    int rear;
public:
    CircularDeque(int initialSize = 0) {
        buffer = new T[initialSize];
        capacity = initialSize;
        size = 0;
        front = 0;
        rear = 0;
    }
    ~CircularDeque() {
        delete[] buffer;
    }
    bool isEmpty() const {
        return size == 0;
    }
    int getSize()const {
        return size;
    }

    void push_back(const T& value) {
        buffer[rear] = value;
        rear = (rear + 1) % capacity;
        if (size < capacity) size++;
        else front = (front + 1) % capacity; // если полный — сдвигаем front
    }
    void push_front(const T& value) {
        front = (front - 1 + capacity) % capacity;
        buffer[front] = value;
        if (size < capacity) size++;
        else rear = (rear - 1 + capacity) % capacity; // если полный — сдвигаем rear
    }

    T pop_front() {
        if (size == 0) throw std::out_of_range("Deque is empty");
        T val = buffer[front];
        front = (front + 1) % capacity;
        size--;
        return val;
    }

    T pop_back() {
        if (size == 0) throw std::out_of_range("Deque is empty");
        rear = (rear - 1 + capacity) % capacity;
        T val = buffer[rear];
        size--;
        return val;
    }


    T& front_elem() {
        if (size == 0) throw std::out_of_range("Deque is empty");
        return buffer[front];
    }


    T& back_elem() {
        if (size == 0) throw std::out_of_range("Deque is empty");
        return buffer[(rear - 1 + capacity) % capacity];
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
        return buffer[(front + index) % capacity];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
        return buffer[(front + index) % capacity];
    }
};

int main() {
    CircularDeque<int> dq1;
    std::cout << "Is empty: " << dq1.isEmpty() << '\n';
    std::cout << "Size: " << dq1.getSize() << '\n';
    CircularDeque<int> dq(5);

    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(0);

    std::cout << "Front: " << dq.front_elem() << '\n'; // 0
    std::cout << "Back: " << dq.back_elem() << '\n';   // 2

    int val = dq.pop_front();
    std::cout << "Popped: " << val << '\n';           // 0
    std::cout << "Size: " << dq.getSize() << '\n';    // 2


    return 0;
}