#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& x : nums) {
            int r = -1;
            int d = 1;
            while ((x & d) != 0) {
                r = x - d;
                d <<= 1;
            }
            x = r;
        }
        return nums;
    }
};

int main() {
    int t;
    cin >> t;
    Solution s;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int& i : arr) cin >> i;
        s.minBitwiseArray(arr);
    }
}
