#include <bits/stdc++.h>
using namespace std;

static const int MAXV = 1'000'000;
int spf[MAXV + 1];

void build_spf()
{
    for (int i = 2; i <= MAXV; i++)
    {
        if (spf[i] == 0)
        {

            for (long long j = (long long)i; j <= MAXV; j += i)
            {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
}

void factorize(int n, map<int, int> &mp)
{
    mp.clear();
    while (n > 1)
    {
        int p = spf[n];
        int cnt = 0;
        while (spf[n] == p)
        {
            n /= p;
            cnt++;
        }
        mp[p] = cnt;
    }
}

void genDivisors(const vector<pair<int, int>> &pf,
                 int idx, long long cur,
                 vector<long long> &divs)
{
    if (idx == (int)pf.size())
    {
        divs.push_back(cur);
        return;
    }
    auto [p, e] = pf[idx];
    long long mul = 1;
    for (int i = 0; i <= e; i++)
    {
        genDivisors(pf, idx + 1, cur * mul, divs);
        mul *= p;
    }
}

int main()
{
    build_spf();

    int T;
    cin >> T;
    while (T--)
    {
        long long x, y;
        int k;
        cin >> x >> y >> k;

        if (x == y)
        {
            cout << 0 << "\n";
            continue;
        }

        map<int, int> fx, fy;
        factorize((int)x, fx);
        factorize((int)y, fy);

        bool impossible = false;
        for (auto &kv : fx)
        {
            int p = kv.first;
            if (fy.find(p) == fy.end())
            {
                impossible = true;
                break;
            }
        }
        if (impossible)
        {
            cout << -1 << "\n";
            continue;
        }
        for (auto &kv : fy)
        {
            int p = kv.first;
            if (fx.find(p) == fx.end() && p > k)
            {

                impossible = true;
                break;
            }
        }
        if (impossible)
        {
            cout << -1 << "\n";
            continue;
        }

        long long root_steps = 0;
        map<int, int> gp;
        long long R = 1;

        {

            long long G = 0;
            long long L = 1;
            bool need_root = false;

            vector<int> shared;
            for (auto &kv : fx)
            {
                int p = kv.first;
                shared.push_back(p);
            }

            for (int i = 0; i < (int)shared.size(); i++)
            {
                int p = shared[i];
                int ep = fx[p];
                if (i == 0)
                    G = ep;
                else
                    G = std::gcd(G, (long long)ep);
            }

            for (int p : shared)
            {
                int ep = fx[p], fp = fy[p];
                if (ep > fp)
                {
                    need_root = true;
                    long long needed = (ep + fp - 1) / fp; // ceil(ep/fp)
                    L = max(L, needed);
                }
            }

            if (!need_root)
            {

                for (auto &kv : fx)
                {
                    gp[kv.first] = kv.second;
                }
                for (auto &kv : fy)
                {
                    int p = kv.first;
                    if (fx.find(p) == fx.end())
                    {
                        gp[p] = 0;
                    }
                }
            }
            else
            {
                int Gint = (int)G;
                map<int, int> gf;
                {
                    int temp = Gint;
                    while (temp > 1)
                    {
                        int p = spf[temp], cnt = 0;
                        while (spf[temp] == p)
                        {
                            temp /= p;
                            cnt++;
                        }
                        gf[p] = cnt;
                    }
                }

                vector<pair<int, int>> pfG;
                for (auto &kv : gf)
                {
                    pfG.emplace_back(kv.first, kv.second);
                }
                vector<long long> allDivs;
                genDivisors(pfG, 0, 1LL, allDivs);
                sort(allDivs.begin(), allDivs.end());
                long long chosenR = -1;
                for (long long d : allDivs)
                {
                    if (d < L)
                        continue;
                    long long temp = d;
                    bool ok = true;
                    while (temp > 1)
                    {
                        int p = spf[temp];
                        if (p > k)
                        {
                            ok = false;
                            break;
                        }
                        temp /= p;
                    }
                    if (ok)
                    {
                        chosenR = d;
                        break;
                    }
                }
                if (chosenR < 0)
                {
                    cout << -1 << "\n";
                    impossible = true;
                }
                if (impossible)
                    continue;
                R = chosenR;
                for (int p : shared)
                {
                    int ep = fx[p];
                    gp[p] = (int)(ep / R);
                }
                for (auto &kv : fy)
                {
                    int p = kv.first;
                    if (fx.find(p) == fx.end())
                    {
                        gp[p] = 0;
                    }
                }

                long long rem = R;
                root_steps = 0;
                vector<long long> divsR = allDivs;
                sort(divsR.begin(), divsR.end(), greater<long long>());

                while (rem > 1)
                {
                    long long best = -1;
                    for (long long d : divsR)
                    {
                        if (d > rem)
                            continue;
                        if (d > k)
                            continue;
                        if (rem % d == 0)
                        {
                            best = d;
                            break;
                        }
                    }
                    rem /= best;
                    root_steps++;
                }
            }
        }

        if (impossible)
            continue;

        map<int, int> Df;
        {
            for (auto &kv : fy)
            {
                int p = kv.first;
                int fp = kv.second;
                int gp_exp = (gp.count(p) ? gp[p] : 0);
                int diff = fp - gp_exp;
                if (diff < 0)
                {
                }
                else if (diff > 0)
                {
                    if (p > k)
                    {

                        impossible = true;
                        break;
                    }
                    Df[p] = diff;
                }
            }
        }
        if (impossible)
        {
            cout << -1 << "\n";
            continue;
        }

        long long mult_steps = 0;
        if (!Df.empty())
        {
            vector<pair<int, int>> pfD;
            for (auto &kv : Df)
            {
                pfD.emplace_back(kv.first, kv.second);
            }
            vector<long long> allDivsD;
            genDivisors(pfD, 0, 1LL, allDivsD);
            sort(allDivsD.begin(), allDivsD.end(), greater<long long>());

            long long remD = 1;
            for (auto &kv : Df)
            {
                int p = kv.first, e = kv.second;
                while (e--)
                    remD *= p;
            }
            mult_steps = 0;
            while (remD > 1)
            {
                long long best = -1;
                for (long long d : allDivsD)
                {
                    if (d > remD)
                        continue;
                    if (d > k)
                        continue;
                    if (remD % d == 0)
                    {
                        best = d;
                        break;
                    }
                }
                remD /= best;
                mult_steps++;
            }
        }

        if (impossible)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << (root_steps + mult_steps) << "\n";
        }
    }

    return 0;
}