#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   private:
    bool isPrime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;

        if (n % 2 == 0) return false;

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }

   public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        unordered_set<int> primeInNums;
        for (int i : nums) {
            if (isPrime(i)) {
                primeInNums.insert(i);
            }
        }

        unordered_map<int, vector<int>> teleports;
        for (int p : primeInNums) {
            for (int i = 0; i < n; i++) {
                if (nums[i] % p == 0) {
                    teleports[p].push_back(i);
                }
            }
        }

        queue<int>         q;
        vector<bool>       visited(n, false);
        unordered_set<int> usedPrime;

        q.push(0);
        visited[0] = true;

        int jumps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int i = q.front();

                q.pop();
                if (i == n - 1) return jumps;

                if (i - 1 >= 0 && !visited[i - 1]) {
                    visited[i - 1] = true;
                    q.push(i - 1);
                }
                if (i + 1 >= 0 && !visited[i + 1]) {
                    visited[i + 1] = true;
                    q.push(i + 1);
                }

                if (isPrime(nums[i])) {
                    int p = nums[i];
                    if (!usedPrime.count(p)) {
                        usedPrime.insert(p);

                        for (int nxtIdx : teleports[p]) {
                            if (!visited[nxtIdx]) {
                                visited[nxtIdx] = true;
                                q.push(nxtIdx);
                            }
                        }
                    }
                }
            }
            jumps++;
        }
        return -1;
    }
};
