#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        bool flag = true;
        vector<int> arr(n);
        arr.push_back()
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'Y' && s[i] == s[i + 1]) {
                cout << "NO" << endl;
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        }
    }
}
