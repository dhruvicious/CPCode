#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> coords(n);
        vector<int> xs(n), ys(n);

        for (int i = 0; i < n; ++i) {
            cin >> coords[i].first >> coords[i].second;
            xs[i] = coords[i].first;
            ys[i] = coords[i].second;
        }

        // Find min1, min2, max1, max2 for x and y along with their indices
        vector<pair<int, int>> x_sorted, y_sorted;
        for (int i = 0; i < n; ++i) {
            x_sorted.emplace_back(coords[i].first, i);
            y_sorted.emplace_back(coords[i].second, i);
        }

        sort(x_sorted.begin(), x_sorted.end());
        sort(y_sorted.begin(), y_sorted.end());

        int min_x1 = x_sorted[0].first, idx_min_x1 = x_sorted[0].second;
        int min_x2 = x_sorted[1].first;
        int max_x1 = x_sorted[n - 1].first, idx_max_x1 = x_sorted[n - 1].second;
        int max_x2 = x_sorted[n - 2].first;

        int min_y1 = y_sorted[0].first, idx_min_y1 = y_sorted[0].second;
        int min_y2 = y_sorted[1].first;
        int max_y1 = y_sorted[n - 1].first, idx_max_y1 = y_sorted[n - 1].second;
        int max_y2 = y_sorted[n - 2].first;

        auto get_area = [](int min_x, int max_x, int min_y, int max_y) -> ll {
            return 1LL * (max_x - min_x + 1) * (max_y - min_y + 1);
        };

        ll base_area = get_area(min_x1, max_x1, min_y1, max_y1);
        ll min_area = base_area;

        set<int> extreme_indices = {idx_min_x1, idx_max_x1, idx_min_y1, idx_max_y1};

        for (int idx : extreme_indices) {
            int new_min_x = INT_MAX, new_max_x = INT_MIN;
            int new_min_y = INT_MAX, new_max_y = INT_MIN;

            for (int i = 0; i < n; ++i) {
                if (i == idx) continue;
                new_min_x = min(new_min_x, coords[i].first);
                new_max_x = max(new_max_x, coords[i].first);
                new_min_y = min(new_min_y, coords[i].second);
                new_max_y = max(new_max_y, coords[i].second);
            }

            ll new_area = get_area(new_min_x, new_max_x, new_min_y, new_max_y);
            min_area = min(min_area, new_area);
        }

        cout << min_area << "\n";
    }
}

int main() {

    solve();

    return 0;
}