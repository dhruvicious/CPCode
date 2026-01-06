#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int sumFourDivisors(vector<int> nums) {
        int totalSum = 0;

        for (int num : nums) {
            int divisorSum = 0;
            int count = 0;

            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    count++;
                    divisorSum += i;

                    if (i != num / i) {
                        count++;
                        divisorSum += num / i;
                    }
                }
                if (count > 4) break;
            }
            if (count == 4) totalSum += divisorSum;
        }
        return totalSum;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& i : nums) {
        cin >> i;
    }
    Solution s;
    cout << s.sumFourDivisors(nums);
}
