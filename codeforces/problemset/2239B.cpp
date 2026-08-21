// problem link: https://codeforces.com/contest/2239/problem/B
// written by a rando

#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;

void solve()
{
    int n, d;
    cin >> n >> d;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<ll> pre(2 * n + 1);
    for (int i = 0; i < 2 * n; i++)
    {
        pre[i + 1] = pre[i] + a[i % n];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll cur = a[i] * 2 * d - (pre[i + d + 1] - pre[i + 1]) - (pre[i + n] - pre[i + n - d]);
        if (cur > 0)
            ans += cur;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}