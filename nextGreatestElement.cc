#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1) {
        stack<int> st;
        vector<int> nge(nums1.size());

        for (int i = 0; i < nums1.size(); i++) {
            while (!st.empty() && nums1[st.top()] < nums1[i]) {
                nge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            nge[st.top()] = -1;
            st.pop();
        }
        return nge;
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}