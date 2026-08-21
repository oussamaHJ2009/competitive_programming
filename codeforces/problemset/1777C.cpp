// problem link: https://codeforces.com/contest/1777/problem/C
// written by a rando

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    vector<vector<int>> div(n);

    for (int i = 0; i < n; i++)
    {
        for (int f = 1; f * f <= a[i]; f++)
        {
            if (a[i] % f == 0)
            {
                if (f <= m)
                    div[i].push_back(f);
                if (a[i] / f <= m && f != a[i] / f)
                    div[i].push_back(a[i] / f);
            }
        }
    }

    int l = 0;
    int ans = 1e9;

    vector<int> cnt(m + 1,0);

    int num = 0;

    auto check = [&](vector<int> cur)
    {
        bool ret = true;
        for (auto c : cur)
            if (cnt[c] <= 1)
                ret = false;
        return ret;
    };

    auto del = [&](vector<int> cur)
    {
        for (auto c : cur)
        {
            cnt[c]--;
            if (!cnt[c])
                num--;
        }
    };

    auto add = [&](vector<int> cur)
    {
        for (auto c : cur)
        {
            cnt[c]++;
            if (cnt[c] == 1)
                num++;
        }
    };

    for (int r = 0; r < n; r++)
    {
        add(div[r]);
        while (l < r && check(div[l]))
        {
            del(div[l]);
            l++;
        }

        if (num == m)
            ans = min(ans, a[r] - a[l]);
    }

    cout << (ans == 1e9 ? -1 : ans) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}