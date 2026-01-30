#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int& i : arr) cin >> i;

        function<long long()> compVal = [&]() -> long long {
            long long res = 0;
            int currmx = 0;
            for (int i : arr) {
                currmx = max(currmx, i);
                res += currmx;
            }
            return res;
        };

        long long ans = compVal();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(arr[i], arr[j]);

                long long currVal = compVal();
                ans = max(currVal, ans);

                swap(arr[i], arr[j]);
            }
        }
        cout << ans << '\n';
    }
}
