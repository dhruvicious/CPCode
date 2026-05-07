#include <algorithm>
#include <cmath>
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

class Solution {
   private:
    void rotateArray(vector<int>& arr, int k) {
        k %= arr.size();
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
    }

    void antiRotateArray(vector<int>& arr, int k) {
        k %= arr.size();
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
        reverse(arr.begin(), arr.end());
    }

    int F(vector<int>& arr) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i] * i;
        }
        return sum;
    }

   public:
    int maxRotateFunction(vector<int>& nums) {
        int maxRot = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            rotateArray(nums, i);
            maxRot = max(F(nums), maxRot);
            antiRotateArray(nums, i);
        }
        return maxRot;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}
