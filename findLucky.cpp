#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freqMap;
        for(int a:arr){
            freqMap[a]++;
        }      
        for(auto& [c,f]:freqMap){
            if(c==f){
                return c;
            }
        }
        return -1;
    }
    int findLucky2(vector<int>& arr){
        int LuckyNum=-1;
        sort(arr.begin(), arr.end());
        int n =arr.size();
        for(int i =1;i<n;i++){
            int cnt=1;
            while(i<n && arr[i]==arr[i-1]){
                cnt++; ++i;
            }
            if(cnt==arr[i-1]){
                LuckyNum=arr[i-1];
            }
        }
        return LuckyNum;
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