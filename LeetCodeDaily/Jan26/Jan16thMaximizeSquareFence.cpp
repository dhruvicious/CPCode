#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    unordered_set<int> getEdges(vector<int>& fences, int border) {
        unordered_set<int> st;
        fences.push_back(1);
        fences.push_back(border);
        sort(fences.begin(), fences.end());
        for (int i = 0; i < fences.size(); i++) {
            for (int j = i + 1; j < fences.size(); j++) {
                st.insert(fences[j] - fences[i]);
            }
        }
        return st;
    }

   public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        auto hEdges = getEdges(hFences, m);
        auto vEdges = getEdges(vFences, n);
        int res = 0;
        for (auto e : hEdges) {
            if (vEdges.contains(e)) {
                res = max(res, e);
            }
        }
        if (res == 0) {
            res = -1;
        } else {
            res = 1ll * res * res % 1000000007;
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    Solution s;
    while (t--) {
        int n, m;
        vector<int> hFences(m), vFences(n);
        for (int& i : hFences) cin >> i;
        for (int& i : vFences) cin >> i;
        s.maximizeSquareArea(m, n, hFences, vFences);
    }

    return 0;
}
