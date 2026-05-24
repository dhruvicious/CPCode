#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>
// and whatever else you need
using namespace std;

void solve() {
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string s;
        string ans;
        getline(cin, s);
        ans.push_back(s[0]);
        for (int i = 0; i < s.size(); i++) {
            if (s[i - 1] == ' ') {
                ans.push_back(s[i]);
            }
        }
        cout << ans << endl;
    }
}

int main() {
    solve();
    return 0;
}