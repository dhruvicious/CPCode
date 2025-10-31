#include <iostream>
#include <vector>
using namespace std;

bool allEven(const vector<int> &arr) {
    for (int i : arr) {
        if (i % 2 != 0) return false;
    }
    return true;
}

bool allOdd(const vector<int> &arr) {
    for (int i : arr) {
        if (i % 2 == 0) return false;
    }
    return true;
}
void PrintArr(vector<int> &arr) {
    for (int& i : arr) {
        cout << i << " ";
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);

        for (int& i : nums) {
            cin >> i;
        }
        if (allEven(nums) || allOdd(nums)) {
            PrintArr(nums);
        }else{
            sort(nums.begin(), nums.end());
            PrintArr(nums);
        }
    }

    return 0;
}