#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
    public:
        int maximum69Number (int num) {
            vector<int> arrnum=numToArr(num);
            for(int& num:arrnum){
                if(num==6){
                    num=9;
                    break;
                }
            }
            int ans;
            for(int num:arrnum){
                ans=ans*10+num;
            }
            return ans;
        }
    private:
        vector<int> numToArr(int num){
            vector<int> arr;
            while(num){
                arr.push_back(num%10);
                num=num/10;
            }
            reverse(arr.begin(), arr.end());
            return arr;
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