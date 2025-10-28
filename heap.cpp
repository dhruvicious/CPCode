#include <bits/stdc++.h>
using namespace std;

class MinHeap {
   private:
    void heapify(int i) {
        int left = 2 * i, right = left + 1;
        int mi = i;
        if (left < v.size() && v[left] < v[mi]) {
            mi = left;
        }
        if (right < v.size() && v[right] < v[mi]) {
            mi = right;
        }

        if (i != mi) {
            swap(v[i], v[mi]);
            heapify(mi);
        }
    }

   public:
    vector<int> v;
    MinHeap() { v.push_back(-1); }

    void push(int data) {
        v.push_back(data);

        int c = v.size() - 1;
        int p = c / 2;

        while (p > 0 && v[c] < v[p]) {
            swap(v[p], v[c]);
            p /= 2;
            c /= 2;
        }
    }

    int top() { return v[1]; }

    bool empty() { return v.size() == 1; }

    void pop() {
        swap(v[1], v[v.size() - 1]);
        v.pop_back();
        heapify(1);
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return 0;
}