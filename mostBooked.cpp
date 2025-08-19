#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<int> usage(n,0);
        priority_queue<int, vector<int>, greater<>> freeRooms;
        for(int i = 0; i < n; i++) freeRooms.push(i);

        using P= pair<long long,int>;
        priority_queue<P, vector<P>, greater<>> occupiedRooms;

        for(auto& m:meetings){
            long long start=m[0], end=m[i];

            while(!occupiedRooms.empty() && occupiedRooms.top().first<=start){
                freeRooms.push(occupiedRooms.top().second);
                occupiedRooms.pop();
            }
            if(!freeRooms.empty()){
                int room = freeRooms.top();
                freeRooms.pop();
                ++usage[room];
                occupiedRooms.emplace(end,room);
            }else{
                auto [availTime, room]=occupiedRooms.top();
                occupiedRooms.pop();
                long long newEnd=availTime+(end-start);
                ++usage[room];
                occupiedRooms.emplace(newEnd, room);
            }
        }
        int maxRoom=0;
        for(int i =0;i<n;i++){
            if(usage[i]>usage[maxRoom]){maxRoom=i;}
        }

        return maxRoom;
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