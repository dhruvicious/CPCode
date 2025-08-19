#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
public:
    int minimizeMax(vector<int>& nums, int p){
        int n=nums.size();
        sort(all(nums));
        int left=0;
        int right=nums[n-1]-nums[0];
        while(left<right){
            int mid=left+(right-left)/2;
            if(canMakePairs(nums, p, mid)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }

private:
    bool canMakePairs(vector<int> nums, int p, int maxDiff){
        int count=0;
        int i =0;
        while(i<nums.size()-1){
            if(nums[i+1]-nums[i]<=maxDiff){
                count++;
                i+=2;
            }else{
                i+=1;
            }
        }
        return count>=p;
    }
};


int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    return 0;
}