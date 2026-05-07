#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i     = low;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i++], arr[j]);
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

int partition2(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i     = low + 1;
    int j     = high;

    while (true) {
        while (i <= j && arr[i] <= pivot) i++;
        while (i <= j && arr[j] > pivot) j--;

        if (i >= j) break;
        swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition2(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    int LOW_CONST = 0;
    quickSort(arr, LOW_CONST, n - 1);
    for (int i : arr) cout << i << " ";
    cout << endl;
    return 0;
}
