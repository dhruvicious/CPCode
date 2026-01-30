#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
   public:
    int centeredSubarrays(vector<int>& nums) {
        int c = 0;
        for (int l = 0; l < nums.size(); l++) {
            long long sum = 0;
            unordered_set<long long> exists;

            for (int r = l; r < nums.size(); r++) {
                sum += nums[r];
                exists.insert(nums[r]);

                if (exists.find(sum) != exists.end()) {
                    c++;
                }
            }
        }
        return c;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}
