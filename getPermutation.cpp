#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
public:
    string getPermutation(int n, int k){
        vector<int> nums(n);
        for(int i =0;i<n;i++) nums[i]=i+1;
        k--;
        string result;

        while(n--){
            int f=fact(n);
            int index=k/f;
            result+=to_string(nums[index]);
            nums.erase(nums.begin()+index);
            k%=f;
        }
        return result;
    }
private:
    int fact(int n){
        if(n==0) return 1;
        return n*fact(n-1);
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