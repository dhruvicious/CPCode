#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void IO(int argC, char* argV[]) {
    const char* inputFile  = argC > 3 ? argV[1] : "input.txt";
    const char* outputFile = argC > 3 ? argV[2] : "output.txt";
#ifdef ONLINE_JUDGE
    freopen(inputFile, "r", stdin);
    freopen(outputFile, "w", stdout);
#endif
}

int main(int argC, char* argV[]) {
    fastIO();
    IO(argC, argV);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) {
            int val;
            cin >> val;
            p[val] = i;
        }

        vector<int> a(n);
        for (int& i : a) cin >> i;
        bool possible = true;

        for (int i = 0; i < n - 1; i++) {
            if (p[a[i]] > p[a[i + 1]]) {
                possible = false;
                break;
            }
        }
        cout << (possible ? "Yes" : "No") << endl;
    }
    return 0;
}
