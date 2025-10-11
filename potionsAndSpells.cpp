#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        vector<int> results(spells.size());
        sort(potions.begin(), potions.end());
        int i = 0; 
        for (int spell : spells) {
            long long target = (success + spell - 1) / spell;
            int left=0;
            int right = potions.size()-1;
            while(left<=right){
                int mid = left+(right-left)/2;
                if(potions[mid]>=target){
                    right = mid-1;
                }else left = mid+1;
            }
            results[i]=potions.size()-left;
            i++;
        }
        return results;
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return 0;
}