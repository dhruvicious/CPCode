#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

class Fancy {
   private:
    vector<long long> seq;
    long long         add = 0;
    long long         mul = 1;

   public:
    Fancy() {}

    void append(int val) {
        long long inv_mul = power(mul, MOD - 2, MOD);
        long long stored  = ((val - add) % MOD + MOD) % MOD * inv_mul % MOD;
        seq.push_back(stored);
    }

    void addAll(int inc) { add = (add + inc) % MOD; }

    void multAll(int m) {
        mul = mul * m % MOD;
        add = add * m % MOD;
    }

    int getIndex(int idx) {
        if (idx >= 0 && idx < seq.size()) {
            return (seq[idx] * mul % MOD + add) % MOD;
        } else {
            return -1;
        }
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
