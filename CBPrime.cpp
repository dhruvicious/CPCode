#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

vector<int> CBPrimes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

bool isCBNumber(int n){
    if(n==0 || n==1) return false;
    for(int p: CBPrimes){
        if(n==p) return true;
        else if(n%p==0) return false;
    }
    return true;
}


int32_t main() {
    fastio
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n;
    string s;
    cin>>n>>s;
    vector<bool> visited(n, false);
    int count=0;

    for(int len =0;len<=n;len++){
        for(int i =0; i+len<=n;i++){
            string sub = s.substr(i, len);
            long long num= stoll(sub);
            
            if(isCBNumber(num)){
                bool free = true;
                for (int k = i; k < i + len; k++) {
                    if (visited[k]) { free = false; break; }
                }
                if (free) {
                    count++;
                    for (int k = i; k < i + len; k++) visited[k] = true;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}