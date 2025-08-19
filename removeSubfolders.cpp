#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

class Solution{
public:
    vector<string> removeSubfolders(vector<string> &folder){
        sort(folder.begin(), folder.end());
        vector<string> auxArr;
        auxArr.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string last=auxArr.back();
            if(folder[i].substr(0, last.size())==last && folder[i][last.size()]=='/'){
                continue;
            }else{
                auxArr.push_back(folder[i]);
            }
        }
        return auxArr;
    }
};

int32_t main(){
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<vector<string>> test_cases = {
        {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"},                        // Expected: {"/a", "/c/d", "/c/f"}
        {"/x", "/x/y", "/x/y/z", "/w", "/w/x"},                          // Expected: {"/x", "/w"}
        {"/home", "/home/user", "/home/user/docs", "/var", "/var/log"},  // Expected: {"/home", "/var"}
        {"/alpha", "/alpha/beta", "/gamma", "/delta"},                   // Expected: {"/alpha", "/gamma", "/delta"}
        {"/a/b/c", "/a/b", "/a"},                                        // Expected: {"/a"}
        {"/p/q/r", "/p/q", "/p"},                                        // Expected: {"/p"}
        {"/z", "/z1", "/z/z1", "/z/z2", "/z1/z2"},                       // Expected: {"/z", "/z1"}
        {"/data", "/data1", "/data2", "/data/backup", "/data2/archive"}, // Expected: {"/data", "/data1", "/data2"}
        {"/abc", "/abcd", "/abc/def", "/abcd/efg", "/abc/ghi"},          // Expected: {"/abc", "/abcd"}
        {"/r", "/r/s", "/r/s/t", "/r/s/t/u", "/r2", "/r3"},              // Expected: {"/r", "/r2", "/r3"}
    };
    Solution s;
    for(vector<string> v:test_cases){
        vector<string> ans=s.removeSubfolders(v);
        for(string a:ans){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    return 0;
}