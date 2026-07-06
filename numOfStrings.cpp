#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (const string& w : patterns) {
            size_t pos = word.find(w);
            if (pos != string::npos) {
                count++;
            }
        }
        return count;
    }
};

int main() {
}
