#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'
#define vi vector<int>
#define vc vector<char>

vi findKDistantIndics(vi& nums, int key, int k) {
    set<int> result;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        if (nums[i] == key) {
            int start = max(0, i - k);
            int end = min(size - 1, i + k);
            for (int j = start; j <= end; j++) {
                result.insert(j);
            }
        }
    }
    return vi(result.begin(), result.end());
}

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    return 0;
}