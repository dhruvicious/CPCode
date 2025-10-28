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
#define int long long
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

// --- Write your solve() function here ---
void solve() {
    int n;
    cin>>n;
    
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

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration.count() << " ms" << endl;
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