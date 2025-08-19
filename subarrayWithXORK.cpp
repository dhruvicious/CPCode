#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
public:
    int subarrayWithXorK(vector<int>& nums, int k){
        unordered_map<int, int> freq;
        int prefixXOR=0, count=0;

        for(int num: nums){
            prefixXOR ^=num;
            if(prefixXOR==k){
                count++;
            }
            if(freq.find(prefixXOR^k)!=freq.end()){
                count+=freq[prefixXOR^k];
            }
            freq[prefixXOR]++;
        }
        return count;
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