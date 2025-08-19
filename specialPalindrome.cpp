#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
public:
    long long specialPalindrome(long long n){
        long long x=n+1;
        while(true){
            string s= to_string(x);
            if(isPalindrome(s) && isSpecial(s)) return x;
            x++;
        }
    }
private:
    bool isPalindrome(const string& s){
        int left=0, right=s.size()-1;
        while(left<right){
            if(s[left]!=s[right]) return false;
            left++;right--;
        }
        return true;
    }

    bool isSpecial(const string& s){
        vector<int> freq(10,0);
        for(char c: s) freq[c-'0']++;

        for(int i =0;i<10;i++){
            if(freq[i]!=0 && freq[i]!=i) return false;
        }
        return true;
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