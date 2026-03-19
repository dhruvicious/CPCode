// #include <cstdio>
// #include <iostream>

// using namespace std;

// int sum(int a, int b) {
//     a = a + b;
//     return a;
// }

// void sum(int* a, int* b) {
//     cout << "a Pointer: " << a << endl;
//     cout << "b Pointer: " << b << endl;
//     cout << "Value of a: " << *a << endl;
//     cout << "Value of b: " << *b << endl;
//     *a = *a + *b;
//     cout << "Value of a: " << *a << endl;
//     cout << "Value of b: " << *b << endl;
//     return;
// }

// int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     int var1 = 10;
//     int var2 = 20;
//     int* var1_p = &var1;
//     int* var2_p = &var2;

//     cout << "Var1 Pointer: " << var1_p << endl;
//     cout << "Var2 Pointer: " << var2_p << endl;

//     var1 = sum(var1, var2);
//     sum(var1_p, var2_p);
//     cout << "Var1: " << var1 << endl;
//     cout << "Var2: " << var2 << endl;
//     // cout << var1 << endl;
// }

#include <cstdio>
#include <iostream>
#include <utility>

using namespace std;

void myreverse(int* arr, int n) {
    int l = 0;
    int r = n - 1;
    while (l < r) {
        swap(arr[l++], arr[r--]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int arr[100] = {0};
    int n = 10;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    myreverse(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
