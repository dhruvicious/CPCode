#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),[](const vector<int>& a,const vector<int>& b ){
            return a[0]<b[0];
        });
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int day=0, i=0, res=0, n=events.size();

        while(i<n || !minHeap.empty()){
            if(minHeap.empty()){
                day=events[i][0];
            }
            while(i<n && events[i][0]<=day){
                minHeap.push(events[i++][1]);
            }
            while(!minHeap.empty() && minHeap.top()<day){
                minHeap.pop();
            }
            if(!minHeap.empty()){
                minHeap.pop();
                res++;
                day++;
            }
        }
        return res;
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