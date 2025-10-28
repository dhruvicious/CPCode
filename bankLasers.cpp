#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> devicesPerRow(bank.size());
        for (string& s : bank) {
            int count = 0;
            for (char c : s) {
                if (c == '1') count++;
            }
            if (count > 0) devicesPerRow.push_back(count);
        }

        int totalBeam = 0;
        for (int i = 1; i < devicesPerRow.size(); i++) {
            totalBeam += devicesPerRow[i - 1] * devicesPerRow[i];
        }
        return totalBeam;
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<string> bank;
    string s;
    while (cin >> s) {
        bank.push_back(s);
    }
    Solution sol;
    cout << "Total Beams: " << sol.numberOfBeams(bank);
    return 0;
}