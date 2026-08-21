// problem link: https://codeforces.com/problemset/problem/1158/A
// written by a rando

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> b(n), g(m);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < m; i++)
        cin >> g[i];
    sort(b.begin(), b.end());
    sort(g.begin(), g.end());
    if (b[n - 1] > g[0])
    {
        cout << -1 << '\n';
        return;
    }
    ll ans = 0;
    for (int i = 0; i < n-2; i++)
    {
        ans+=m*b[i];
    }
    for (int i = 1; i < m; i++)
    {
        ans+=g[i];
    }
    ans+=(m-1)*b[n-2];
    if(b[n-1]==g[0])ans+=g[0]+b[n-2];
    else ans+=b[n-1]+g[0];
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}