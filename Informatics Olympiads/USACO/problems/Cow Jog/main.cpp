#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty())
    {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve()
{
    int n;
    ll T;
    cin >> n >> T;
    vector<ll> p(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x >> p[i];
        p[i] = x + p[i] * T;
    }
    reverse(p.begin(), p.end());
    vector<ll> dp;
    for (ll x : p)
    {
        int i = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
        if (i == (int)dp.size())
            dp.push_back(x);
        else
            dp[i] = x;
    }
    cout<<(int)dp.size()<<'\n';
}

int main()
{
    setIO("cowjog");
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}