#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> a, vector<int> b) {
    unordered_map<int, int> map;
    vector<int> ans;

    for (int i : a) {
        map[i]++;
    }
    for (int i : b) {
        if (map[i] > 0) {
            ans.push_back(i);
            map[i]--;
        }
    }
    return ans;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;

    vector<int> result = intersection(a, b);

    for (int& i : result) cout << i << endl;
    
    return 0;
}