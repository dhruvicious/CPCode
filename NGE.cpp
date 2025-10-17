#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreatestElement(const vector<int> &arr) {
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            nge[i] = -1;
        } else {
            nge[i] = st.top();
        }
        st.push(arr[i]);
    }
    return nge;
}

int32_t main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &num : nums) {
        cin >> num;
    }
    vector<int> ans = nextGreatestElement(nums);
    for (int &num : ans) {
        cout << num << " ";
    }
    return 0;
}