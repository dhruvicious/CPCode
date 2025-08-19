#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

int maxDiff(int num){
    string numStr=to_string(num);
    int maxVal=num;
    int minVal=num;
    vector<char> DIGITS={'0','1','2','3','4','5','6','7','8','9'};
    //Maximize
    for(char n:DIGITS){
        string replaced=numStr;
        replace(replaced.begin(),replaced.end(),n ,'9');
        if(replaced[0]!='0'){
            maxVal=max(maxVal, stoi(replaced));
        }
    }
    //Minimize
    for(char n:DIGITS){
        if (n == numStr[0]) {
            string replaced = numStr;
            replace(replaced.begin(), replaced.end(), n, '1');
            if (replaced[0] != '0') {
                minVal = min(minVal, stoi(replaced));
            }
        } else {
            string replaced = numStr;
            replace(replaced.begin(), replaced.end(), n, '0');
            if (replaced[0] != '0') {
                minVal = min(minVal, stoi(replaced));
            }
        }
    }
    return abs(maxVal-minVal);
}

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    return 0;
}