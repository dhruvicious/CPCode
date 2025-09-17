#include <bits/stdc++.h>
using namespace std;

int countWays(vector<int>& arr, int i, vector<int>& g1, vector<int>& g2) {
    if (i == arr.size()) {
        int sum1 = accumulate(g1.begin(), g1.end(), 0);
        int sum2 = accumulate(g2.begin(), g2.end(), 0);
        return sum1 == sum2 ? 1 : 0;
    }

    g1.push_back(arr[i]);
    int c1 = countWays(arr, i + 1, g1, g2);
    g1.pop_back();

    g2.push_back(arr[i]);
    int c2 = countWays(arr, i + 1, g1, g2);
    g2.pop_back();

    return c1 + c2;
}

void printWays(vector<int>& arr, int i, vector<int>& g1, vector<int>& g2) {
    if (i == arr.size()) {
        int sum1 = accumulate(g1.begin(), g1.end(), 0);
        int sum2 = accumulate(g2.begin(), g2.end(), 0);
        if (sum1 == sum2) {
            for (auto& x : g1) cout << x << " ";
            cout << "and ";
            for (auto& x : g2) cout << x << " ";
            cout << endl;
        }
        return;
    }

    g1.push_back(arr[i]);
    printWays(arr, i + 1, g1, g2);
    g1.pop_back();

    g2.push_back(arr[i]);
    printWays(arr, i + 1, g1, g2);
    g2.pop_back();
}

int32_t main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& num : arr) cin >> num;

    vector<int> g1, g2;

    printWays(arr, 0, g1, g2);
    cout << endl << countWays(arr, 0, g1, g2) << endl;
    return 0;
}