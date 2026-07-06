#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        for (auto vec1 : intervals) {
            for (auto vec2 : intervals) {
                if (vec1 != vec2 && vec2[0] <= vec1[0] && vec2[1] >= vec1[1]) {
                    count++;
                    break;
                }
            }
        }
        return (intervals.size() - count);
    }
    int removeCoveredIntervalsOPT(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0]) return a[1] > b[1];
                 return a[0] < b[0];
             });
        int ans    = 0;
        int maxEnd = -1;
        for (auto& interval : intervals) {
            if (interval[1] > maxEnd) {
                ans++;
                maxEnd = interval[1];
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
