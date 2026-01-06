#include <cstddef>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>

template <typename T>
class DynamicArr {
   private:
    std::unique_ptr<T[]> arr;
    int _size;
    int _capacity;

    void reallocate(int newCapacity) {
        std::unique_ptr<T[]> newArr = std::make_unique<T[]>(newCapacity);

        for (int i = 0; i < _size; i++) {
            newArr[i] = std::move(arr[i]);
        }
        arr = std::move(newArr);
        _capacity = newCapacity;
    }

   public:
    DynamicArr(int n) : _size(0), _capacity(n) {
        if (n < 0) {
            throw std::invalid_argument("Enter a Valid Argument to the Object of the type Dynamic Array");
        }
        arr = std::make_unique<T[]>(n);
    }

    ~DynamicArr() = default;

    DynamicArr(const DynamicArr& other) : _size(other._size), _capacity(other._capacity) {
        arr = std::make_unique<T[]>(other._capacity);

        for (size_t i = 0; i < _size; i++) {
            arr[i] = other.arr[i];
        }
    }
    DynamicArr& operator=(const DynamicArr& other) {
        if (this == &other) {
            return *this;
        }
        std::unique_ptr<T[]> newArr = std::make_unique<T[]>(other._capacity);

        for (size_t i = 0; i < other._size; i++) {
            newArr[i] = other.arr[i];
        }
        arr = std::move(newArr);
        _size = other._size;
        _capacity = other._capacity;

        return *this;
    }

    DynamicArr(DynamicArr&& other) noexcept
        : arr(std::move(other.arr)), _size(other._size), _capacity(other._capacity) {
        other._size = 0;
        other._capacity = 0;
    }

    DynamicArr& operator=(DynamicArr&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        arr = std::move(other.arr);
        _size = other._size;
        _capacity = other._capacity;

        other._size = 0;
        other._capacity = 0;

        return *this;
    }

    T& operator[](int index) {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("Index is out of Range for the Object of the Type DynamicArr.");
        }
        return arr[index];
    }
    const T& operator[](int index) const {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("Index is out of Range for the Object of the Type DynamicArr.");
        }
        return arr[index];
    }
    void pushBack(const T& val) {
        if (_size == _capacity) reallocate(_capacity == 0 ? 1 : _capacity * 2);
        arr[_size] = val;
        _size++;
    }
    void pushBack(T&& val) {
        if (_size == _capacity) {
            reallocate(_capacity == 0 ? 1 : _capacity * 2);
        }
        arr[_size] = std::move(val);  // Move assignment
        _size++;
    }
    void popBack() {
        if (_size == 0) {
            throw std::out_of_range("PopBack called on an empty Object of type DynamicArr");
        }
        _size--;
    }
    int size() const { return _size; }
    int getCapacity() const { return _capacity; }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int n;
    std::cin >> n;
    return 0;
}
