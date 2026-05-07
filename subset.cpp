#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

void subset(vector<int>& arr, size_t index, vector<int>& curr,
            vector<vector<int>>& res) {
    if (index == arr.size()) {
        res.push_back(curr);
        return;
    }

    subset(arr, index + 1, curr, res);
    curr.push_back(arr[index]);
    subset(arr, index + 1, curr, res);
    curr.pop_back();
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
    vector<vector<int>> res;
    vector<int>         curr;
    subset(arr, 0, curr, res);
    reverse(res.begin(), res.end());

    for (vector<int>& vec : res) {
        for (int& i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
}
