#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long last_selected = LLONG_MIN;
        int count = 0;

        for (int i = 0; i < n; i++)
        {

            if (a[i] >= last_selected + 2)
            {
                count++;
                last_selected = a[i];
            }
        }

        cout << count << "\n";
    }

    return 0;
}