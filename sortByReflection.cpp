#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        long long totalscore = 0;
        int n = damage.size();
        for (int i = 0; i < n; i++) {
            long long currentHP = hp;
            for (int j = i; j < n; j++) {
                currentHP -= damage[j];
                if (currentHP >= requirement[j]) {
                    totalscore++;
                }
            }
        }
        return totalscore;
    }
};
class Solution2 {
   public:
    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0){
            
        } }

    int largestPrime(int n) {}
};
©leetcode

    int
    main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return 0;
}
