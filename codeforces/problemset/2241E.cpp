// problem link: https://codeforces.com/contest/2241/problem/E
// written by a rando

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> T(n, vector<ll>());
    vector<ll> a(n);
    vector<ll> sub(n,1);
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        T[--u].push_back(--v);
        T[v].push_back(u);
    }

    function<void(ll, ll)> dfs = [&](ll cur, ll prev)
    {
        vector<ll> val;
        for (auto nxt : T[cur])
        {
            if (nxt != prev)
            {
                dfs(nxt, cur);
                val.push_back(sub[nxt]);
                sub[cur] += sub[nxt];
            }
        }
        if (n-sub[cur])val.push_back(n - sub[cur]);
        bool ps = false;
        ll j = 0;
        while((j + 1) * (j + 1) <= a[cur])j++;
        if (j * j == a[cur])ps = 1;
        if(!ps)return;
        ll trip = 0, sum = 0, pairs = 0;
        for (auto x : val)
        {
            trip += x * pairs;
            pairs += x * sum;
            sum += x;
        }
        ans += trip + pairs;
    };
    dfs(0, -1);

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}