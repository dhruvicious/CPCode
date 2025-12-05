#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) {
        cin >> i;
        i = i > 0 ? i : -i;
    }
    int ans = *min_element(arr.begin(), arr.end());
    cout << ans;
    return 0;
}