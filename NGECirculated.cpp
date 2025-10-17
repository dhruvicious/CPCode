#include <bits/stdc++.h>
using namespace std;

vector<int> NGECirc(const vector<int> &nums) {
    int n = nums.size();
    vector<int> nge(n, -1);
    vector<int> extendedArr(2 * n);
    for (int i = 0; i < n; i++) {
        extendedArr[i] = nums[i];
        extendedArr[i + n] = nums[i];
    }

    stack<int> st;

    for (int i = (2 * n) - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= extendedArr[i]) {
            st.pop();
        }

        if (i < n) {
            if (!st.empty()) {
                nge[i % n] = st.top();
            }
        }
        st.push(extendedArr[i]);
    }
    return nge;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int &i : nums) {
        cin >> i;
    }
    vector<int> ans = NGECirc(nums);

    for (int &a : ans) {
        cout << a << " ";
    }
    return 0;
}