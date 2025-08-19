#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // bruteForce
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> ans(2);
        for(int i=0;i<nums.size();i++){
            int searchTarget=target-nums[i];
            for(int j=0;j<nums.size();j++){
                if(nums[j]==searchTarget){
                    ans[0]=i;
                    ans[1]=j;
                }
            }
        }
        return ans;
    }

    //optimized
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            int targetSearch =target-nums[i];
            if(map.find(targetSearch)!=map.end()){
                return {map[targetSearch],i};
            }
            map[nums[i]]=i;
        }
        return {};
    }
};
int main(){

    return 0;
}