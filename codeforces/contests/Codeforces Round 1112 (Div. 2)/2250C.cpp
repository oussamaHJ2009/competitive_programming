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
    for (int i = 0; i < n - 1; i++)
    {
        int v;
        cin >> v;
        if (n - v <= i)
        {
            ans = (ans + (C(v, i) * f[n - i]) % mod) % mod;
        }
        if (n - v <= n - i)
        {
            ans = (ans + (C(v, n - i) * f[i]) % mod) % mod;
        }
    }
    cout<<ans<<'\n';
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