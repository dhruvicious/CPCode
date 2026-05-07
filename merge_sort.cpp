#include <iostream>
#include <vector>

using namespace std;

vector<int> myMerge(vector<int>& left, vector<int>& right) {
    vector<int> srted;
    int         p1=0, p2=0;
    while (p1 < left.size() && p2 < right.size()) {
        if (left[p1] < right[p2]) {
            srted.push_back(left[p1++]);
        } else {
            srted.push_back(right[p2++]);
        }
    }
    while (p1 < left.size()) srted.push_back(left[p1++]);
    while (p2 < right.size()) srted.push_back(right[p2++]);

    return srted;
}

vector<int> mergeSort(vector<int>& arr) {
    int n   = arr.size();
    int mid = n / 2;
    // base-case
    if (n <= 1) return arr;

    vector<int> leftHalf(arr.begin(), arr.begin() + mid);
    vector<int> rightHalf(arr.begin() + mid, arr.end());

    vector<int> leftHalfSorted  = mergeSort(leftHalf);
    vector<int> rightHalfSorted = mergeSort(rightHalf);

    return myMerge(leftHalfSorted, rightHalfSorted);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;

    arr = mergeSort(arr);
    for (int i : arr) cout << i;

    return 0;
}
