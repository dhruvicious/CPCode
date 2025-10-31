#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace chrono;

#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vb vector<bool>
#define ld long double
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define vc vector<char>
#define vs vector<string>
#define s string
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define cneg cout << -1 << endl;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

// Read this whenever you feel like giving up
// Its not you versus the however many people giving the contest
// Its you versus the problem
// You are not competing with anyone
// You are competing with yourself
// You are trying to be better than you were yesterday
// You are trying to be better than you were 5 minutes ago
// You are trying to be better than you were 5 seconds ago
// So keep going
// Keep pushing
// and keep trying until you finish the problem
// what sperates the bad from the good  -> choice
// what seprates the good from the best -> effort

void print(vi a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void print(vvi a) {
    for (int i = 0; i < a.size(); i++) {
        print(a[i]);
    }
    cout << endl;
}

void print(auto a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;
}

void permuteString(string& s, int i) {
    if (i == s.size()) {
        cout << s << endl;
        return;
    }
    for (int j = i; j < s.size(); j++) {
        swap(s[i], s[j]);
        permuteString(s, i + 1);
        swap(s[i], s[j]);
    }
}

bool ratInMaze(vector<vector<char>>& maze, vector<vector<int>>& ans, int n,
               int m, int i, int j) {
    if (i == m - 1 && j == n - 1) {
        ans[i][j] = 1;
        for (vector<char>& vec : maze) {
            for (char& i : vec) {
                cout << i << " ";
            }
            cout << endl;
        }
        return true;
    }
    ans[i][j] = 1;

    if (j + 1 < m && maze[i][j + 1] != 'X') {
        if (ratInMaze(maze, ans, n, m, i, j + 1)) return true;
    }
    if (i + 1 < n && maze[i + 1][j] != 'X') {
        if (ratInMaze(maze, ans, n, m, i + 1, j)) return true;
    }
    ans[i][j] = 0;
    return false;
}

#undef int
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    fastio();

    auto start1 = high_resolution_clock::now();

    int m, n;
    cin >> m >> n;
    vector<vector<char>> maze(m, vector<char>(n));
    for (auto& vec : maze) {
        for (auto& i : vec) {
            cin >> i;
        }
    }
    vector<vector<int>> ans;
    ratInMaze(maze, ans, n, m, 0, 0);
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cout << "Time: " << duration.count() << " ms" << endl;
#endif

    return 0;
}

// Code with passion, conquer with persistence. Keep coding, keep winning.

// ALL SNIPPETS
// qa: Base template
// ia: Input array
// ye: yes
// no: no
// os: ordered set
// bp: Binary exponentiation
// bpm: Binary exponentiation with modulo
// bsmx: Binary search for max
// bsmn: Binary search for min
// quad: Quadratic Equation
// segtree: STree class snippet
// ig: input graph
// in: input n
// inm: input n m
// constructpath: For loop to construct path snippet
// matrixexpo: Matrix class and exponentiation
// combo: nCr
// modinv: Mod Inverse
// dijkstra: Dijkstra algo for sparse graph where m ~= n, T.C = O(nlogn + m)
// floydwarshall: floyd warshall dist all pairs
// dgcycle: Directed Cycle check
// ugcycle: UnDirected Cycle check