#include <bitset>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void generateGrey(int n) {
    vector<int> res;
    int         total = 1 << n;
    for (int i = 0; i < total; i++) {
        int grey = i ^ (i >> 1);
        cout << bitset<16>(grey).to_string().substr(16 - n) << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    generateGrey(n);
    return 0;
}
