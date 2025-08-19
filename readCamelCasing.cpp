#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

vector<string> readCamelCase(string& s){
    int read=1;
    vector<string> words;
    string currWord;
    currWord+=s[0];
    while(read<s.size()){
        if(s[read]>='A' && s[read]<='Z'){
            words.push_back(currWord);
            currWord=s[read];
        } 
        else currWord+=s[read];
        read++;
    }
    if(!currWord.empty()) words.push_back(currWord);
    return words;
}

int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    getline(cin, s);
    vector<string> words=readCamelCase(s);
    for (string word : words) {
        cout << word << endl;
    }
    return 0;
}