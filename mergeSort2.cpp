#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

void MergeSort(vector<int>::iterator start, vector<int>::iterator end) {
    if (distance(start, end) <= 1) return;
    vector<int>::iterator middle = start;
    advance(middle, distance(start, end) / 2);
    MergeSort(start, middle);
    MergeSort(middle, end);

    inplace_merge(start, middle, end);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n = 0;
        cin >> n;
        vector<int> arr(n);
        for (int& i : arr) cin >> i;
        MergeSort(arr.begin(), arr.end());
        for (int& i : arr) cout << i;
    }
}
