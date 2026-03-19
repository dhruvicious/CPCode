#include <iostream>

using namespace std;

class Solution {
   private:
    const long long MOD = 1e9 + 7;

    long long ModPow(long long base, long long exp) {
        if (exp == 0) return 1;

        long long half = ModPow(base, exp / 2);
        long long res  = (half * half) % MOD;
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        return res;
    }

   public:
    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos  = n / 2;

        long long evenWays = ModPow(5, evenPos);
        long long oddWays  = ModPow(4, oddPos);

        return (evenWays * oddWays) % MOD;
    }
};


int main(){
    
}