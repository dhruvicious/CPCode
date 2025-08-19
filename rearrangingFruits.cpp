#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
#define vi vector<int>

class Solution{
public:
    ll minCost(vi& basket1, vi& basket2){
        unordered_map<int, int> freqDiff;
        int minCost=INT_MAX;

        for(int fruit:basket1){
            freqDiff[fruit]++;
            minCost=min(minCost, fruit);
        }

        for(int fruit: basket2){
            freqDiff[fruit]--;
            minCost=min(minCost, fruit);
        }

        vector<int> surplus;
        for(auto [cost,count]:freqDiff){
            if(count%2!=0) return -1;
            int excess=abs(count)/2;
            for(int i =0;i<excess;i++){
                surplus.push_back(cost);
            }
        }
        
        int k=surplus.size()/2;
        nth_element(surplus.begin(), surplus.begin()+k, surplus.end());

        long long totalCost=0;
        for(int i =0;i<k;i++){
            totalCost+=min(surplus[i], minCost*2);
        }
        return totalCost;
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