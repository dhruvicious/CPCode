#include <iostream>

using namespace std;

int largestValBelowN(int n, int x) {
    return n - 1 - ((n - 1) % x);
}

int sum(int lastVal, int firstVal) {
    int terms = ((lastVal - firstVal) / firstVal) + 1;
    return (terms * (firstVal + lastVal)) / 2;
}

int solve(int n) {
    int sum3Mul  = sum(largestValBelowN(n, 3), 3);
    int sum5Mul  = sum(largestValBelowN(n, 5), 5);
    int sum15Mul = sum(largestValBelowN(n, 15), 15);
    return ((sum3Mul + sum5Mul) - sum15Mul);
}

int main() {
    int n;
    cin >> n;
    cout << solve(n);
}
