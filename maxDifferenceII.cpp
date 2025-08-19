#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{

    public:
        int maxDifference(string s, int k){
            int n = s.size();
            int maxDiff=INT_MIN;
            unordered_map<char, int> freq;

            int left;
            for(int right=0;right<n;right++){
                freq[s[right]]++;
                while(right-left+1>=k){
                    int maxOdd=INT_MIN;
                    int minEven=INT_MAX;
                    for(auto&p:freq){
                        if(p.second%2==1){
                            maxOdd=max(maxOdd, p.second);
                        }
                        if(p.second%2==0){
                            minEven=min(minEven, p.second);
                        }
                    }
                    if(maxOdd!=INT_MIN && minEven!=INT_MAX){
                        maxDiff=max(maxDiff, maxOdd-minEven);
                    }
                    freq[s[left]]++;
                    if(freq[s[left]]==0){
                        freq.erase(s[left]);
                    }
                    left++;
                }
            }
            return (maxDiff==INT_MIN)? -1:maxDiff;
        }
};

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    int k;
    getline(cin, s);
    cin>>k;

    return 0;
}