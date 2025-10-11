#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& heights);

int maxArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> leftMax(n);
    vector<int> rightMax(n);

    leftMax[0] = heights[0];
    rightMax[n - 1] = heights[n - 1];

    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], heights[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], heights[i]);
    }
    int maxWater = 0;
    for (int i = 0; i < n; i++) {
        maxWater += max(0, min(leftMax[i], rightMax[i])) - heights[i];
    }
    return maxWater;
}

int maxArea(vector<int>& heights) {
    int left = 0;
    int right = heights.size() - 1;
    int maxWater = 0;

    while (left < right) {
        int width = abs(left - right);
        int minHeight = min(heights[left], heights[right]);
        int currWater = width * minHeight;
        maxWater = currWater > maxWater ? currWater : maxWater;

        if(heights[left]<heights[right]) left++;
        else right--;
    }
    return maxWater;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int& num : heights) {
        cin >> num;
    }
    maxArea(heights);
    return 0;
}