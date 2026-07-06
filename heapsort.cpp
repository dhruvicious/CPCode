#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void sort(vector<int>& arr) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int a : arr) {
        q.push(a);
    }
    arr.clear();
    while (!q.empty()) {
        arr.push_back(q.top());
        q.pop();
    }
}

int main() {
    vector<int> arr = {3, 4, 6, 4, 10, 9, 8, 7};
    sort(arr);
    for (int i : arr) {
        cout << i << " ";
    }
}
