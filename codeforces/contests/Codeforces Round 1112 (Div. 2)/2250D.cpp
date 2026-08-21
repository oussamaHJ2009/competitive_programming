// problem link: https://codeforces.com/contest/2250/problem/C
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

const ll mod = 998244353;
const int N = 1000001;
ll f[N];

ll C(ll n, ll k)
{
    return (f[n] / f[k]) % mod;
}

void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        ll v;
        cin >> v;
        if (v >= i)
            ans = (ans + (i * (C(v - 1, i - 1) * f[n - i]) % mod) % mod) % mod;

        if (v >= n - i)
            ans = (ans + ((n - i) * (C(v - 1, n - i - 1) * f[i]) % mod) % mod) % mod;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = (f[i - 1] * i) % mod;

    while (t--)
    {
        solve();
    }

    return 0;
}