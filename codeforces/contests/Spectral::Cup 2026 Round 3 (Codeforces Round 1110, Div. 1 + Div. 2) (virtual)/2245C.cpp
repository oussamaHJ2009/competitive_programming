// problem link: https://codeforces.com/contest/2245/problem/C
// authored by a human (i guess?)

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    k ^= n;
    vector<int> a;
    int hbk = 1 << (31 - (k == 0 ? 0 : __builtin_clz(k))), hbn = 1 << (31 - __builtin_clz(n));
    if (hbk > hbn)
    {
        cout << "NO\n";
        return;
    }
    if (k < n)
    {
        for (int i = 1; i < n; i++)
        {
            if (i != k)
                a.push_back(i);
        }
        a.push_back(0);
        if (k)
            a.push_back(k);
    }
    else if ((k ^= n - 1) < n - 1)
    {
        for (int i = 1; i < n-1; i++)
        {
            if (i != k)
                a.push_back(i);
        }
        a.push_back(0);
        if (k)
            a.push_back(k);
        a.push_back(n-1);
    }
    else
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (auto x : a)
        cout << x << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}