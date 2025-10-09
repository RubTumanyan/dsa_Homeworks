// Create a custom Vector class that would support all the functionality given in main.cpp.

// Again: Declare your functions inside your class, but define them outside of it.
#pragma once
#include <cstddef>
#include <initializer_list>
#include <utility>

template <typename T>
class Vector {
    T *array = nullptr;
    size_t size_;
    size_t capacity_;

public:
    Vector() : array(nullptr), size_(0), capacity_(0) {}

    explicit Vector(size_t size)
            : array(static_cast<T*>(::operator new(sizeof(T) * size))),
              size_(size),
              capacity_(size)
    { //
        for (size_t i = 0; i < size_; ++i) {
            new(array + i) T{};
        }
    }

    Vector(size_t size, const T& value)
            : array(static_cast<T*>(::operator new(sizeof(T) * size))),
              size_(size),
              capacity_(size)
    {
        for (size_t i = 0; i < size_; ++i) {
            new(array + i) T(value);
        }
    }

    Vector(std::initializer_list<T> lst)
            : array(static_cast<T *>(::operator new(sizeof(T) * lst.size()))),
              size_(lst.size()),
              capacity_(lst.size())
    {
        size_t i = 0;
        for (const T& obj : lst) {
            new(array + i) T(obj);
            ++i;
        }
    }

    Vector(const Vector &other)
            : size_(other.size_), capacity_(other.capacity_)
    {
        array = static_cast<T *>(::operator new(sizeof(T) * other.capacity_));
        for (size_t i = 0; i < size_; ++i) {
            new(array + i) T(other.array[i]);
        }
    }

    Vector(Vector&& other) noexcept
            : array(other.array), size_(other.size_), capacity_(other.capacity_)
    {
        other.array = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    Vector& operator=(const Vector &other) {
        if (this == &other) return *this;

        clear();
        ::operator delete(array);

        size_ = other.size_;
        capacity_ = other.capacity_;
        array = static_cast<T *>(::operator new(sizeof(T) * other.capacity_));
        for (size_t i = 0; i < size_; ++i) {
            new(array + i) T(other.array[i]);
        }

        return *this;
    }

    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            clear();
            ::operator delete(array);

            array = other.array;
            size_ = other.size_;
            capacity_ = other.capacity_;

            other.array = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }

    const T &operator[](size_t index) const {
        return array[index];
    }
    T &operator[](size_t index) {
        return array[index];
    }

    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }

    void push_back(const T &el) {
        if (size_ == capacity_) {
            if (capacity_ == 0) {
                reserve(1);
            } else {
                reserve(capacity_ * 2);
            }
        }
        new(array + size_) T(el);
        ++size_;
    }

    void push_back(T&& el) {
        if (size_ == capacity_) {
            if (capacity_ == 0) {
                reserve(1);
            } else {
                reserve(capacity_ * 2);
            }
        }
        new(array + size_) T(std::move(el));
        ++size_;
    }

    template<typename... Args>
    void emplace_back(Args&&... args) {
        if (size_ == capacity_) {
            if (capacity_ == 0) {
                reserve(1);
            } else {
                reserve(capacity_ * 2);
            }
        }
        new(array + size_) T(std::forward<Args>(args)...);
        ++size_;
    }

    void pop_back() {
        if (size_ > 0) {
            array[size_ - 1].~T();
            --size_;
        }
    }

    void clear() {
        for (size_t i = 0; i < size_; i++) {
            array[i].~T();
        }
        size_ = 0;
    }
void swap(Vector& other) noexcept {
        std::swap(array, other.array);
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
    }

    void reserve(size_t new_capacity) {
        if (new_capacity <= capacity_) return;

        T *newArr = static_cast<T *>(::operator new(sizeof(T) * new_capacity));
        for (size_t i = 0; i < size_; ++i) {
            new(newArr + i) T(std::move(array[i]));
            array[i].~T();
        }
        ::operator delete(array);
        array = newArr;
        capacity_ = new_capacity;
    }

    void shrink_to_fit() {
        if (capacity_ == size_) return;

        if (size_ == 0) {
            ::operator delete(array);
            array = nullptr;
            capacity_ = 0;
            return;
        }

        T* newArr = static_cast<T*>(::operator new(sizeof(T) * size_));
        for (size_t i = 0; i < size_; i++) {
            new(newArr + i) T(std::move(array[i]));
            array[i].~T();
        }
        ::operator delete(array);
        array = newArr;
        capacity_ = size_;
    }

    bool operator==(const Vector &other) const {
        if (size_ != other.size_) return false;
        for (size_t i = 0; i < size_; ++i) {
            if (array[i] != other[i]) return false;
        }
        return true;
    }

    T& at(size_t index) {
        return array[index];
    }

    const T& at(size_t index) const {
        return array[index];
    }

    T& front() {
        return array[0];
    }
    const T& front() const {
        return array[0];
    }

    T& back() {
        return array[size_ - 1];
    }
    const T& back() const {
        return array[size_ - 1];
    }

    T* data() {
        return array;
    }
    const T* data() const {
        return array;
    }


    bool operator!=(const Vector &other) const { return !(*this == other); }

    ~Vector() {
        clear();
        ::operator delete(array);
    }
};
