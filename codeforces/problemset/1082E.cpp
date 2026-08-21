#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const ll N = 500067;
const ll INF = int(1e9);

void solve()
{
    ll n, c;
    cin >> n >> c;
    vector<ll>dp(n+1);
    vector<ll>dp2(N,INF);
    vector<ll>cnt(N);
    vector<ll>a(n);
    ll cntc = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == c)
            cntc++;
    }
    ll ans = cntc;
    for (ll i = 0; i < n; i++)
    {
        cnt[a[i]]++;
        if (a[i] != c)
        {
            dp[i] = cnt[a[i]] - cnt[c];
            ans = max(ans, dp[i] - (dp2[a[i]] != INF ? dp2[a[i]]-1 : 0) + cntc);
            dp2[a[i]] = min(dp2[a[i]], dp[i]);
        }
    }
    //do the same thing but from the other side idk ?????
    dp=vector<ll>(n+1);
    dp2=vector<ll>(N,INF);
    cnt=vector<ll>(N);
    for (ll i = n-1; i >= 0; i--)
    {
        cnt[a[i]]++;
        if (a[i] != c)
        {
            dp[i] = cnt[a[i]] - cnt[c];
            ans = max(ans, dp[i] - (dp2[a[i]] != INF ? dp2[a[i]]-1 : 0) + cntc);
            dp2[a[i]] = min(dp2[a[i]], dp[i]);
        }
    }

    cout<<ans<<'\n';
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