#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        
        int count0 = count(s.begin(), s.end(), '0');
        int count1 = n - count0;
        
        
        int total_pairs = n / 2;
        
        
        if(k < 0 || k > total_pairs) {
            cout << "NO\n";
            continue;
        }
        
        
        int bad_pairs = total_pairs - k;
        
        
        int remaining0 = count0 - bad_pairs;
        int remaining1 = count1 - bad_pairs;
        
        
        if(remaining0 < 0 || remaining1 < 0) {
            cout << "NO\n";
            continue;
        }
        
        if(remaining0 % 2 != 0 || remaining1 % 2 != 0) {
            cout << "NO\n";
            continue;
        }
        
        
        int good_pairs_from_0 = remaining0 / 2;
        int good_pairs_from_1 = remaining1 / 2;
        
        if(good_pairs_from_0 + good_pairs_from_1 == k) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    solve();
    return 0;
}