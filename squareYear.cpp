#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        int year = stoi(s);
        int root = sqrt(year);
        if (root * root == year){
            cout << 0 << " " << root << endl;
        }else{
            cout << -1 << endl;
        }
    }
}

int main()
{
    solve();
    return 0;
}