#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[1000] = {0};

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int freq[2001] = {0};
    for (int i = 0; i < n; i++) {
        int index = arr[i] + 1000;
        freq[index]++;
    }
    bool seen[1001] = {false};

    for (int i = 0; i < 2001; i++) {
        if (freq[i] > 0) {
            if (seen[freq[i]]) {
                cout << "false";
                return 0;
            }
            seen[freq[i]] = true;
        }
    }
    cout << "true" << endl;
    return 0;
}