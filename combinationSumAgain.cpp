#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<vector<int>> ans;

    void backtrack(int target, int index, vector<int> curr,
                   vector<int> candidates) {
        int n = candidates.size();
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        if (index == n) return;

        for (int j = index; j < n; j++) {
            if (target - candidates[j] < 0) return;
            curr.push_back(candidates[j]);
            backtrack(target - candidates[j], j, curr, candidates);
            curr.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        backtrack(target, 0, curr, candidates);
        return ans;
    }
}

int main() {
}
