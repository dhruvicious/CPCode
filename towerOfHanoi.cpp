#include <iostream>

using namespace std;

void TOH(int n, int src, int aux, int dest) {
    if (n == 1) {
        cout << src << " " << dest << endl;
        return;
    }

    TOH(n - 1, src, dest, aux);
    cout << src << " " << dest << endl;
    TOH(n - 1, aux, src, dest);
}

int main() {
    int n;
    cin >> n;

    long long moves = (1LL << n) - 1;
    cout << moves << endl;
    TOH(n, 1, 2, 3);

    return 0;
}
