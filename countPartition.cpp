#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0;
        for (int i : nums) totalSum += i;
        if (totalSum % 2 != 0) {
            return 0;
        } else {
            return nums.size() - 1;
        }
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    
    
    return 0;
}
