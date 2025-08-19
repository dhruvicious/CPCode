#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
public:
    static bool cmp(string& a, string& b){
        return a+b>b+a;
    }

    string largestNumber(vector<int>& nums){
        vector<string> strNums;
        for(int num: nums){
            strNums.push_back(to_string(num));
        }
        sort(strNums.begin(), strNums.end(), cmp);
        if(strNums[0]=="0") return "0";
        string result;
        for(string& s:strNums){
            result+=s;
        }
        return result;
    }
};

int32_t main() {
    fastio
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    return 0;
}