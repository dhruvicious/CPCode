#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> duplicateZeros(vector<int> arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                arr.insert(arr.begin() + i + 1, 0);
                i++;
            }
        }
        arr.resize(n);
        return arr;
    }
};

int main() {
    int t;
    cin >> t;
    Solution s;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int& i : arr) cin >> i;
        vector<int> res = s.duplicateZeros(arr);
        for (int& i : res) cout << i << " ";
        cout << endl;
    }
}
