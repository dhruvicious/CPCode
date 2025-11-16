#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

class Solution {
   public:
    // void WeirdAlgo(long long n) {
    //     while (n != 1) {
    //         cout << n << " ";
    //         if (n % 2 == 0) {
    //             n /= 2;
    //         } else {
    //             n = 3 * n + 1;
    //         }
    //     }
    //     cout << "1";
    // }

    ////using maths
    /*
    int missingNumber(vector<int>& arr, int n){
        long long total= 1LL*n*(n+1)/2;
        long long sum=0;
        for(int num: arr) sum+=num;
        return total-sum;
    }
    */

    ////XOR Based Solution
    /*
    int missingNumber( int n, vector<int>& nums ) {
        int xor1=0, xor2=0;
        for(int i =1; i<=n;i++) xor1 ^= i;
        for(int x: nums) xor2 ^= x;
        return xor1 ^ xor2;
    }
    */

    /*
    int maxRep(string s){
        if (s.empty()) return 0;
        char currChar=s[0];
        int currCount=0;
        for(size_t i=0; i<s.size();i++){
            int maxCount=0;
            if(s[i]==currChar){
                currCount++;
            }else{
                maxCount=max(maxCount, currCount);
                currCount=1;
                currChar=s[i];
            }
        }
        maxCount=max(maxCount, currCount);
        return maxCount;
    }
    */

    /*
    long long increasingArray(vector<int> arr) {
        long long ans = 0, msf = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < msf) {
                ans += (msf - arr[i]);
            }else{
                msf=arr[i];
            }
        }
        return ans;
    }
    */

    // void permutations(long long n) {
    //     if (n == 2 || n == 3)
    //         cout << "NO SOLUTION\n";
    //     else {
    //         for (int i = 2; i <= n; i += 2) {
    //             cout << i << " ";
    //         }
    //         for (int i = 1; i <= n; i += 2) {
    //             cout << i << " ";
    //         }
    //         cout << '\n';
    //         return;
    //     }
    // }

    // void numberSpiral(ll X, ll Y) {
    //     if (Y > X) {
    //         ll ans = (Y - 1) * (Y - 1);
    //         ll add = 0;

    //         if (Y % 2 != 0) {
    //             add = X;
    //         } else {
    //             add = 2 * Y - X;
    //         }
    //         cout << ans + add << "\n";
    //     } else {
    //         ll ans = (X - 1) * (X - 1);
    //         ll add = 0;

    //         if (X % 2 == 0) {
    //             add = Y;
    //         } else {
    //             add = 2 * X - Y;
    //         }
    //         cout << ans + add << "\n";
    //     }
    // }

    // void twoKnights(long long k) {
    //     for (long long n = 1; n <= k; n++) {
    //         if (n == 1) {
    //             cout << 0 << "\n";
    //             continue;
    //         }
    //         long long total = ((n * n * (n * n - 1)) / 2);
    //         long long attack = 4 * (n - 1) * (n - 2);
    //         cout << total - attack << '\n';
    //     }
    // }

    // void twoSets(long long n) {
    //     long long s = (n * (n + 1)) / 2;
    //     if (s % 2 != 0)
    //         cout << "NO" << '\n';
    //     else {
    //         cout << "YES" << '\n';
    //         vector<long long> arr1;
    //         vector<long long> arr2;
    //         long long target = s / 2;
    //         for (long long i = n; i >= 1; i--) {
    //             if (target >= i) {
    //                 arr1.push_back(i);
    //                 target -= i;
    //             } else {
    //                 arr2.push_back(i);
    //             }
    //         }
    //         cout << arr1.size() << '\n';
    //         for (long long num : arr1) {
    //             cout << num << ' ';
    //         }
    //         cout << '\n' << arr2.size() << '\n';
    //         for (long long num : arr2) {
    //             cout << num << ' ';
    //         }
    //     }
    // }

    // long long bitString(long long base, long long exp, long long mod) {
    //     long long result = 1;
    //     base %= mod;
    //     while (exp > 0) {
    //         if (exp & 1) result = (result * base) % mod;
    //         base = (base * base) % mod;
    //         exp >>= 1;
    //     }
    //     return result;
    // }

    // long long trailingZeroes(long long n) {
    //     long long zeroCount = 0;
    //     long long divisor = 5;

    //     while (divisor <= n) {
    //         zeroCount += n / divisor;
    //         divisor *= 5;
    //     }

    //     return zeroCount;
    // }

    // bool coinPiles(int a, int b) {
    //     return ((a + b) % 3 == 0 && min(a, b) * 2 >= max(a, b));
    // }

    void PalindromeReorder(string& s) {
        vector<int> freq(26, 0);

        for (char c : s) freq[c - 'A']++;
        int oddCount = 0;
        int oddchar = -1;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                oddCount++;
                oddchar = i;
            }
        }

        if (oddCount > 1) {
            cout << "NO SOLUTION" << endl;
            return;
        }
        string left = "";
        for (int i = 0; i < 26; i++) {
            left.append(freq[i] / 2, char('A' + i));
        }

        string middle = "";
        if (oddchar != -1) {
            middle.append(1, char('A' + oddchar));
        }

        string right = left;
        reverse(right.begin(), right.end());

        cout << left + middle + right;
        return;
    }
};

const long long MOD = 1e9 + 7;

int32_t main() {
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution s;
    string str;
    cin >> str;
    s.PalindromeReorder(str);
    return 0;
}