#include <bits/stdc++.h>
using namespace std;

    #define ll long long
    #define all(x) x.begin(), x.end()
    #define fastio ios::sync_with_stdio(false); cin.tie(0);
    #define endl '\n'

int minimumDeletion(string word, int k){
    unordered_map<char, int> freqMap;
    for(char c: word){
        freqMap[c]++;
    }
    
    vector<int> freq;
    for(auto &[c,f]:freqMap){
        freq.push_back(f);
    }

    sort(all(freq));
    int n=freq.size();
    int minDel=INT_MAX;
    
    for(int i=0;i<n;i++){
        int target=freq[i];
        int del=0;

        for(int j=0;j<n;j++){
            if(freq[j]<target) 
                del+=freq[j];
            else if(freq[j]>target+k) 
                del+=freq[j]-(target+k);
        }
        minDel=min(minDel, del);
    }
    return minDel;
}

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    return 0;
}