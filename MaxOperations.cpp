#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int maxOperations(vector<int>& nums, int k){
            map<int, int> mapSet;
            for(int i=0;i<nums.size();i++){
                mapSet[nums[i]]++;
            }
            int operations=0;
            for(auto& [num, freq]:mapSet){
                int complement= k-num;
                if(mapSet.find(complement)!= mapSet.end()){
                    if(num==complement){
                        operations+=freq/2;
                    }
                    else{
                        operations+=min(freq, mapSet[complement]);
                    }
                    mapSet[num]=0;
                    mapSet[complement]=0;
                }
            }
            return operations;
        }
        int MaxOperationsOptimized(vector<int>& nums, int k){
            int counter=0, l=0, r=nums.size()-1;
            sort(nums.begin(), nums.end());
            while(l<r){
                if(nums[l]+nums[r]<k){
                    l++;
                }else if(nums[l]+nums[r]>k){
                    r--;
                }else{
                    counter++;
                    l++;
                    r--;
                }
            }
            return counter;
        }
};

int main() {
    
}