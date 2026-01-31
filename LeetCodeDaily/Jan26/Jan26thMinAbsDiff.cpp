#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
   public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int minAbsDiff = INT_MAX;
        vector<vector<int>> retVal;

        for (int i = 0; i < n - 1; i++) {
            int diff = abs(arr[i] - arr[i + 1]);
            minAbsDiff = min(minAbsDiff, diff);
        }

        for (int i = 0; i < n - 1; i++) {
            if (abs(arr[i] - arr[i + 1]) == minAbsDiff) {
                retVal.push_back({arr[i], arr[i + 1]});
            }
        }
        return retVal;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ofstream timingFile("runtime_analysis.txt");

    int t;
    cin >> t;
    int totalTests = t;  // Preserve original count

    Solution s;
    long double totalTimeMicroseconds = 0.0;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int& i : arr) cin >> i;

        auto start = high_resolution_clock::now();
        s.minimumAbsDifference(arr);
        auto end = high_resolution_clock::now();

        totalTimeMicroseconds += duration_cast<microseconds>(end - start).count();
    }

    long double averageTime = totalTimeMicroseconds / static_cast<long double>(totalTests);

    timingFile << "Average runtime per test case (microseconds): " << averageTime << endl;

    timingFile.close();
    return 0;
}
