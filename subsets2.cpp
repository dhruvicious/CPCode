#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void subset(vector<int>& arr, size_t index, vector<int>& curr,
                vector<vector<int>>& res) {
        if (index == arr.size()) {
            res.push_back(curr);
            return;
        }

        for (int i = index; i < arr.size(); i++) {
            if (i > index && arr[i] == arr[i - 1]) {
                continue;
            }
            curr.push_back(arr[i]);
            subset(arr, i + 1, curr, res);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>         curr;
        vector<vector<int>> res;
        subset(nums, 0, curr, res);
        return res;
    }
};

int main() {
}
