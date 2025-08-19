#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
    public:
        vector<vector<string>> partition(string s){
            vector<string> current;
            vector<vector<string>> result;
            backtrack(s, 0, current, result);
            return result;
        }

    private:
        bool isPalindrome(string& s, int left, int right){
            while(left<right){
                if(s[left]!=s[right]) return false;
                left++;
                right--;
            }
            return true;
        }

        void backtrack(string& s, int start, vector<string>& current, vector<vector<string>>& result){
            if(start==s.size()){
                result.push_back(current);
                return;
            }
            for(int end=start;end<s.size();end++){
                if(isPalindrome(s, start, end)){
                    current.push_back(s.substr(start, end-start+1));
                    backtrack(s, end+1, current, result);
                    current.pop_back();
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