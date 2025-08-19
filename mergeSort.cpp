#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
public:
    int reversePairCount=0;

    vector<int> mergeSort(vector<int>& nums){
        int n=nums.size();
        if(n<=1) return nums;

        int mid=n/2;

        vector<int> left(nums.begin(), nums.begin()+mid);
        vector<int> right(nums.begin()+mid, nums.end());

        return myMerge(mergeSort(left), mergeSort(right));
    };
    
    vector<int> myMerge(vector<int> left, vector<int> right){

        int i =0, j=0;
        while(i<left.size() && j<right.size()){
            if((ll)left[i]>2LL* right[j]){
                reversePairCount+=(left.size()-i);
                j++;
            }else i++;
        }

        vector<int> merged;
        int leftIdx=0;
        int rightIdx=0;

        while(leftIdx<left.size() && rightIdx<right.size()){
            if(left[leftIdx]<=right[rightIdx]) merged.push_back(left[leftIdx++]);
            else merged.push_back(right[rightIdx++]);
        }
        while(leftIdx<left.size()) merged.push_back(left[leftIdx++]);
        while(rightIdx<right.size()) merged.push_back(right[rightIdx++]);
        
        return merged;
    };
    
    int reversePairs(vector<int>& nums) {
        reversePairCount=0;
        mergeSort(nums);
        return reversePairCount;
    };
};

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    return 0;
}