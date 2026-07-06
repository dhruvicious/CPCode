#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    int maxNumberOfBalloons(string text) {
        return min({
            (int) count(text.begin(), text.end(), 'b'),
            (int) count(text.begin(), text.end(), 'a'),
            (int) count(text.begin(), text.end(), 'l'),
            (int) count(text.begin(), text.end(), 'o'),
            (int) count(text.begin(), text.end(), 'n'),
        });
    }
};

int main() {
    return 0;

    Solution s;
    s.maxNumberOfBalloons("balloon");
}
