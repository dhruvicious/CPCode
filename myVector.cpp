#include <iostream>
#include <stdexcept>

using namespace std;

class MyVector {
   private:
    int  size, capacity;
    int* arr;

   public:
    MyVector() {
        capacity = 2;
        size     = 0;
        arr      = new int[capacity];
    }

    ~MyVector() { delete[] arr; }

    void push_back(int val) {
        if (size == capacity) {
            capacity *= 2;
            int* newArr = new int[capacity];
            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
        arr[size++] = val;
    }

    void pop_back() {
        if (size > 0) {
            size--;
        }
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range for the given vector");
        }
        return arr[index];
    }

    int getCapacity() { return capacity; }

    int getSize() { return size; }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    MyVector vec;

    vec.push_back(1);
    vec.push_back(2);
    cout << "Curr Capacity: " << vec.getCapacity() << endl;
    cout << "Curr Size: " << vec.getSize() << endl;
    vec.push_back(3);
    cout << "Curr Capacity: " << vec.getCapacity() << endl;
    cout << "Curr Size: " << vec.getSize() << endl;
    vec.push_back(4);

    vec.print();

    cout << "Value at index 2:" << vec.get(2) << endl;

    vec.pop_back();

    vec.print();
}
