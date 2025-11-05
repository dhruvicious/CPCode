#include <bits/stdc++.h>
using namespace std;

void NegWin(vector<int> &arr, int k){
    queue<int> q;
    for(int i: arr){
        if(i<0) q.push(i);
    }
    int currNeg=INT_MIN;
    int start=0, end=0;

    while(end<k){
        if(arr[end] == q.front()){
            currNeg = q.front();
        }
    }

    while(end < arr.size()){
        if(currNeg!=INT_MIN) cout<<currNeg;
        if(arr[start] == q.front()){
            q.pop();
            currNeg = q.front();
        }
        
        start++;
        end++;
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int& a : arr) {
            cin >> a;
        }
    }
    return 0;
}