#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <stdio.h>
#include <unordered_set>
#include <vector>

using namespace std;

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void FileIO(char* inputFile, char* outputFile) {
#ifndef ONLINE_JUDGE
    freopen(inputFile, "r", stdin);
    freopen(outputFile, "w", stdout);
#endif
}

class Solution {
   public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        for (int i : nums1) {
            st.insert(i);
        }
        for (int i : nums2) {
            if (st.find(i) != st.end()) {
                return i;
            }
        }
        return -1;
    }
    int getCommon2Pt(vector<int>& nums1, vector<int>& nums2) {
        int first = 0, second = 0;
        while (first < nums1.size() && second < nums2.size()) {
            if (nums1[first] < nums2[second]) {
                first++;
            } else if (nums1[first] > nums2[second]) {
                second++;
            } else {
                return nums1[first];
            }
        }
        return -1;
    }

    int getCommonIntersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),
                         back_inserter(res));

        return res.empty() ? -1 : res[0];
    }
};

// argsV[0] -> executable name
// argsV[1] -> input file
// argsV[2] -> output file
int main(int argC, char* argsV[]) {
    fastIO();

    if (argC >= 3) {
        FileIO(argsV[1], argsV[2]);
    }

    return 0;
}
