#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
public:
    int majorityElementN2(vector<int>& nums){
        unordered_map<int, int> freqMap;
        for(int num:nums){
            freqMap[num]++;
        }
        for(auto [c,f] : freqMap){
            if(f>nums.size()/2){
                return c;
            }
        }
        return -1; 
    }

    int majorityElementN3(vector<int>& nums){
        unordered_map<int, int> freqMap;
        for(int num:nums){
            freqMap[num]++;
        }
        for(auto [c,f]:freqMap){
            if(f>nums.size()/3){
                return c;
            }
        }
        return -1;
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