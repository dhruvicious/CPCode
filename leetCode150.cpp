#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <random>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else if (nums2[j] > nums1[i]) {
                nums1[k--] = nums2[j--];
            } else {
                nums1[k--] = nums1[i--];
            }
        }
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }

    int removeElements(vector<int>& nums, int val) {
        int write = 0;
        for (int read = 0; read < nums.size(); read++) {
            if (nums[read] != val) {
                nums[write++] = nums[read];
            }
        }
        return write;
    }

    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int write = 1;
        for (int read = 1; read < nums.size(); read++) {
            if (nums[read] != nums[write - 1]) {
                nums[write++] = nums[read];
            }
        }
        return write;
    }

    int removeDuplicates2(vector<int>& nums) {
        int write = 0;
        for (int num : nums) {
            if (write == 0 || write == 1 || nums[write - 2] != num) {
                nums[write] = num;
                write++;
            }
        }
        return write;
    }

    int majorityElement(vector<int>& nums) {
        int n         = nums.size();
        int candidate = 0, count = 0;
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                candidate = nums[i];
            }
            count += (nums[i] == candidate) ? 1 : -1;
        }
        return candidate;
    }

    void rotateArray(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

    int maxProfit(vector<int>& prices) {
        int minP      = INT_MAX;
        int maxProfit = 0;
        for (int p : prices) {
            minP      = min(minP, p);
            maxProfit = max(maxProfit, p - minP);
        }
        return maxProfit;
    }

    int maxProfit2(vector<int>& prices) {}

    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }

    int jump(vector<int>& nums) {
        int n        = nums.size();
        int jumps    = 0;
        int currEnd  = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == currEnd) {
                jumps++;
                currEnd = farthest;
                if (currEnd >= n - 1) {
                    break;
                }
            }
        }
        return jumps;
    }

    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());

        int count = n;
        for (int cite : citations) {
            if (cite >= count) return count;
            count--;
        }
        return 0;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        int         n = nums.size();
        vector<int> res(n, 1);

        int prefix = 1;
        for (int i = 0; i < n; i++) {
            res[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= suffix;
            suffix *= nums[i];
        }

        return res;
    }

    class RandomizedSet {
       public:
        unordered_set<int> randSet;
        RandomizedSet() {}

        bool insert(int val) {
            bool found = randSet.find(val) != randSet.end();
            if (found) {
                return false;
            } else {
                randSet.insert(val);
                return true;
            }
        }

        bool remove(int val) {
            bool found = randSet.find(val) != randSet.end();
            if (!found)
                return false;
            else {
                randSet.erase(val);
                return true;
            }
        }

        int getRandom() {
            int  randomIndex = rand() % randSet.size();
            auto it          = randSet.begin();
            advance(it, randomIndex);
            return *it;
        }
    };
};
