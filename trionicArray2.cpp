#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
#define ll long long

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void IO(int argsC, char* argsV[]) {
    const char* inputFile = (argsC >= 3) ? argsV[1] : "input.txt";
    const char* outputFile = (argsC >= 3) ? argsV[2] : "output.txt";

#ifndef ONLINE_JUDGE
    freopen(inputFile, "r", stdin);
    freopen(outputFile, "w", stdout);
#endif
}

class Solution {
   public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        const ll INF = -1e18;
        vector<ll> incr1(n, INF);
        vector<ll> dec(n, INF);
        vector<ll> incr2(n, INF);

        incr1[0] = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                incr1[i] = incr1[i - 1] + nums[i];
            } else {
                incr1[i] = nums[i];
            }

            if (nums[i] < nums[i - 1]) {
                if (incr1[i - 1] != INF) dec[i] = incr1[i - 1] + nums[i];
                if (dec[i - 1] != INF) dec[i] = max(dec[i], dec[i - 1] + nums[i]);
            }

            if (nums[i] > nums[i - 1]) {
                ll from_dec = (dec[i - 1] != INF) ? dec[i - 1] + nums[i] : INF;
                ll from_incr2 = (incr2[i - 1] != INF) ? incr2[i - 1] + nums[i] : INF;
                incr2[i] = max(from_dec, from_incr2);
            }
        }
        ll ans = INF;
        for (long long& i : incr2) {
            ans = max(ans, i);
        }
        return ans;
    }
};

int main(int argC, char* argV[]) {
    fastIO();
    IO(argC, argV);
    int t;
    cin >> t;
    Solution s;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int& i : arr) cin >> i;
        s.maxSumTrionic(arr);
    }
}
