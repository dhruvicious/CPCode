#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
public:
    void sortColors(vector<int>& nums){
        int n = nums.size();
        int n1=0,n2=0,n0=0;
        for(int i =0;i<n;i++){
            if(nums[i]==0) n0++;
            if(nums[i]==1) n1++;
            if(nums[i]==2) n2++;
        }
        for(int i =0;i<n;i++){
            if(n0>0){
                nums[i]=0;
                n0--;
                continue;
            }
            if(n1>0){
                nums[i]=1;
                n1--;
                continue;
            }
            if(n2>0){
                nums[i]=2;
                n2--;
                continue;
            }
        }
    }

    void dutchSort(vector<int>& nums){
        int low=0, mid=0, high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid++],nums[low++]);
                
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid], nums[high--]);
            }
        }
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