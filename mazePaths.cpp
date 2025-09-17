#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

int countWays(int N, int M, int i, int j) {
    if (i >= N || j >= M) return 0;
    if (i == N - 1 && j == M - 1) {
        return 1;
    }

    return countWays(N, M, i + 1, j) + countWays(N, M, i, j + 1);
}

void printPaths(int N, int M, int i, int j, string path) {
    if (i >= N || j >= M) return;
    if (i == N-1 && j == M-1) {
        cout << path << " ";
        return;
    }
    printPaths(N, M, i + 1, j, path + "V");
    printPaths(N, M, i, j + 1, path + "H");
}

int32_t main() {
    fastio
// #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int N, M;
    cin >> N >> M;

    printPaths(N, M, 0, 0,"");
    cout<<countWays(N,M,0,0)<<endl;
    return 0;
}