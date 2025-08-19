#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'


class Solution{
public:
    int findKthNumberUnopt(int n, int k){
        vector<string> nums;
        for(int i =1;i<=n;i++){
            nums.push_back(to_string(i));
        }
        sort(all(nums));
        return stoi(nums[k-1]);
    }
    int findKthNumberOpt(int n, int k){
        ll curr=1;
        k-=1;
        while(k>0){
            ll step=countStep(n, curr, curr+1);
            if(step<=k){
                curr+=1;
                k-=step;
            }else{
                curr *=10;
                k-=1;
            }
        }
        return curr;
    }
    

private:
    ll countStep(int n, ll curr, ll next){
        ll steps=0;
        while(curr<=n){
            steps+=min((ll)n+1, next)-curr;
            curr*=10;
            next*=10;
        }
        return steps;
    }

};

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution solution;
    cout<<solution.findKthNumberOpt(13,2)<<endl;
    return 0;
}