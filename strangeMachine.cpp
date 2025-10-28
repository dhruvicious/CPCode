#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<int> queries(q);
        for (int& i : queries) {
            cin >> i;
        }
        vector<int> ans;

        for (int q : queries) {
            int count = 0;
            while (q > 0) {
                int currIndex = count % s.size();
                if (s[currIndex] == 'A') {
                    q = q - 1;
                } else {
                    q = q / 2;
                }
                count++;
            }
            ans.push_back(count);
        }

        for (int a : ans) {
            cout << a << '\n';
        }
    }
    return 0;
}