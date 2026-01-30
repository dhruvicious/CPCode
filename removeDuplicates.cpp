#include <cstdio>
#include <ios>
#include <iostream>
#include <vector>

void fastIO() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
}

void IO(int argsCount, char* argsValue[]) {
    const char* inputFile = argsCount >= 3 ? argsValue[1] : "input.txt";
    const char* outputFile = argsCount >= 3 ? argsValue[2] : "output.txt";
#ifndef ONLINE_JUDGE
    freopen(inputFile, "r", stdin);
    freopen(outputFile, "w", stdout);
#endif
}

class Solution {
   public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        int writeHead = 1;
        for (int readHead = 1; readHead < (int) nums.size(); readHead++) {
            if (nums[readHead] != nums[writeHead - 1]) {
                nums[writeHead] = nums[readHead];
                writeHead++;
            }
        }
        return writeHead;
    }
};

int main(int argsCount, char* argsValue[]) {
    fastIO();
    IO(argsCount, argsValue);
    Solution s;
    std::vector<int> arr = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int ans = s.removeDuplicates(arr);
    std::cout << ans << "\n";
    for (int i = 0; i < ans; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
