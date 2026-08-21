#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

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
    ll m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= m;
        a.push_back(a[i] + m);
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= 2 * n; i++)
    {
        a[i] += a[i - 1];
    }
    ll ans = 1e18;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, -a[i+n/2]-a[i +n -n/2] + a[i] + a[i + n]);
    }

    cout << ans << '\n';
}

int main()
{
    setIO("");
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}