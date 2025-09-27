#include <iostream>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    int arr[100][100];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int top = 0, bottom = M - 1;
    int left = 0, right = N - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            cout << arr[top][i] << ", ";
        top++;

        for (int i = top; i <= bottom; i++)
            cout << arr[i][right] << ", ";
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                cout << arr[bottom][i] << ", ";
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                cout << arr[i][left] << ", ";
            left++;
        }
    }

    cout << "END" << endl;

    return 0;
}