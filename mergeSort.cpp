#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<int> myMerge(vector<int> arr1, vector<int> arr2) {
    vector<int> merged;
    int         left = 0, right = 0;
    while (left < arr1.size() && right < arr2.size()) {
        if (arr1[left] < arr2[right]) {
            merged.push_back(arr1[left++]);
        } else {
            merged.push_back(arr2[right++]);
        }
    }
    while (left < arr1.size()) {
        merged.push_back(arr1[left++]);
    }
    while (right < arr2.size()) {
        merged.push_back(arr2[right++]);
    }
    return merged;
}

vector<int> mergeSort(vector<int> arr) {
    int n = arr.size();
    if (n <= 1) return arr;
    int mid = n / 2;

    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    vector<int> sortedLeft  = mergeSort(left);
    vector<int> sortedRight = mergeSort(right);

    return myMerge(sortedLeft, sortedRight);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) {
        cin >> i;
    }
    arr = mergeSort(arr);
    for (int i : arr) cout << i << " ";
    cout << "\n";
}
