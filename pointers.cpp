#include <iostream>
using namespace std;

void printfunc(int* arr, int n);

void printfunc(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int ar2[n] = {0};
    printfunc(ar2, n);
}
