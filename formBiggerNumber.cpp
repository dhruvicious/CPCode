#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

string solve(vector<int>& nums) {
    vector<string> arr;
    for (int num : nums) arr.push_back(to_string(num));

    sort(arr.begin(), arr.end(),
         [](string s, string t) { return s + t > t + s; });

    if (arr[0] == "0") return "0";

    string result = "";

    for (string& s : arr) result += s;
    return result;
}

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++) cin >> arr[i];
        cout<<solve(arr);
    }
    return 0;
}