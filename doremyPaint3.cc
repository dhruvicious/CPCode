#include <climits>
#include <iostream>
#include <map>
#include <unordered_map>
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
        int n;
        cin >> n;
        vector<int> arr(n);
        map<int, int> freq;
        for (int& i : arr) {
            cin >> i;
            freq[i]++;
        }

        if (freq.size() >= 3) {
            cout << "No\n";
        } else {
            int freq1 = freq.begin()->second;
            int freq2 = freq.rbegin()->second;

            if (freq1 == freq2)
                cout << "Yes\n";
            else if (n % 2 == 1 && abs(freq1 - freq2) == 1)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}