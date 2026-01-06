#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// Recursive Solution using lambda function
int longestCommonSubseq(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    function<int(int, int)> LCS = [&](int i, int j) -> int {
        if (i == n || j == m) {
            return 0;
        } else if (str1[i] == str2[j]) {
            return 1 + LCS(i + 1, j + 1);
        } else {
            return max(LCS(i + 1, j), LCS(i, j + 1));
        }
    };
    return LCS(0, 0);
}

// Recursive Solution using Memoization
int longestCommonSubSeqMem(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    vector<vector<int>> memMat(n, vector<int>(m, -1));

    function<int(int, int)> LCS = [&](int i, int j) -> int {
        if (i == n || j == m) {
            return 0;
        }
        if (memMat[i][j] != -1) {
            return memMat[i][j];
        }
        if (str1[i] == str2[j]) {
            return memMat[i][j] = 1 + LCS(i + 1, j + 1);
        } else {
            return memMat[i][j] = max(LCS(i + 1, j), LCS(i, j + 1));
        }
    };
    return LCS(0, 0);
}

//
int longestCommonSubSeqTopDown()

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string str1, str2;
    cin >> str1 >> str2;
    cout << longestCommonSubseq(str1, str2);
    return 0;
}
