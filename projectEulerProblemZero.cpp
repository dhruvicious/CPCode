#include <iostream>
using namespace std;

long long sumOfOddSquares(long long  n) {
    long long sum = 0;
    for (long long i = 0; i <= n; i++) {
        if ((i * i) % 2 != 0) {
            sum += i * i;
        }
    }
    return sum;
}

int main() {
    long long n   = 961000;
    long long ans = sumOfOddSquares(n);
    cout << ans;

    return 0;
}
