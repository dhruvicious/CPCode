#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return letters[left % letters.size()];
    }
};

int main() {
    int t;
    cin >> t;
    Solution s;
    while (t--) {
        int n;
        cin >> n;
        char target;
        cin >> target;
        vector<char> vec(n);
        for (char& c : vec) cin >> c;
        s.nextGreatestLetter(vec, target);
    }

    return 0;
}
