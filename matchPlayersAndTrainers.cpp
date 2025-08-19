#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution{
public:
    int matchPlayersAndTrainers(vector<int> players, vector<int> trainers){
        int matchCount=0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i=0,j=0;
        while(i<players.size() && j<trainers.size()){
            if(players[i]<=trainers[j]){
                matchCount++;
                i++; j++;
            }else{
                j++;
            }
        }
        return matchCount;
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