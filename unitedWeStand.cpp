#include <algorithm>
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

        sort(arr.begin(), arr.end());
        if (arr.back() == arr[0]) {
            cout << -1 << endl;
            continue;
        } else {
            int i = 0;
            while (arr[i] == arr[0]) i++;
            cout << i << " " << n - i << endl;
            for (int j = 0; j < i; j++) cout << arr[j] << " ";
            for (int j = i; j < n; j++) cout << arr[j] << " ";
        }
    }
    return 0;
}
