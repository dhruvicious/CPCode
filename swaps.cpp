#include <vector>
using namespace std;

class Solution {
   public:
    long long maxSum(vector<int>& nums, int k) {
        int       n    = nums.size();
        long long best = LLONG_MIN;
        for (int windowLen = 1; windowLen <= n; windowLen++) {
            best = max(best, bestSumForLength(nums, windowLen, k));
        }

        return best;
    }

   private:
    long long bestSumForLength(vector<int>& nums, int windowLen, int k) {
        int n = nums.size();
        multiset<int> inside;
        multiset<int> outside;
        long long     windowSum = 0;

        for (int i = 0; i < windowLen; i++) {
            inside.insert(nums[i]);
            windowSum += nums[i];
        }
        for (int i = windowLen; i < n; i++) {
            outside.insert(nums[i]);
        }

        long long best = bestAchievableSum(inside, outside, windowSum, k);

        for (int newStart = 1; newStart + windowLen - 1 < n; newStart++) {
            int valueLeavingWindow  = nums[newStart - 1];
            int valueEnteringWindow = nums[newStart + windowLen - 1];

            inside.erase(inside.find(valueLeavingWindow));
            outside.insert(valueLeavingWindow);
            windowSum -= valueLeavingWindow;

            outside.erase(outside.find(valueEnteringWindow));
            inside.insert(valueEnteringWindow);
            windowSum += valueEnteringWindow;

            best = max(best, bestAchievableSum(inside, outside, windowSum, k));
        }

        return best;
    }
    long long bestAchievableSum(multiset<int>& inside, multiset<int>& outside,
                                long long windowSum, int k) {
        long long sum = windowSum;

        auto smallestInsideIt = inside.begin();
        auto largestOutsideIt = outside.rbegin();

        int swapsUsed = 0;
        while (swapsUsed < k && smallestInsideIt != inside.end()
               && largestOutsideIt != outside.rend()) {
            int smallestInside = *smallestInsideIt;
            int largestOutside = *largestOutsideIt;

            if (largestOutside <= smallestInside) {
                break;
            }

            sum += (largestOutside - smallestInside);

            ++smallestInsideIt;
            ++largestOutsideIt;
            swapsUsed++;
        }

        return sum;
    }
};