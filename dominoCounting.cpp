#include <bits/stdc++.h>
using namespace std;

int numEquivDominoPairs(vector<vector<int>>& dominoes){
    
    map<pair<int, int>, int> visited;
    int count=0;
    
    for(auto& d: dominoes){
        pair<int, int> key ={min(d[0],d[1]), max(d[0],d[1])};
        count+=visited[key];
        visited[key]++;
    }
    return count;
}

int main() {
    
    return 0;
}