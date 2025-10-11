#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    int findRotationPoint(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] < arr[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    int binSearch(vector<int> &arr, int target, int left, int right) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

   public:
    int search(vector<int> &nums, int target) {
        int rotPt = findRotationPoint(nums);
        int Lleft = 0, Lright = rotPt, Rleft = rotPt, Rright = nums.size() - 1;
        return binSearch(nums, target, Lleft, Lright) || binSearch(nums,target, Rleft, Rright);
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return 0;
}