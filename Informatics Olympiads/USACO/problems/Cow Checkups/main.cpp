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
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    vector<vector<ll>> B(n + 1), A(n + 1), pB(n + 1), sB(n + 1);
    set<ll> vals;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        A[a[i]].push_back(i);
        vals.insert(a[i]);
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
        B[b[i]].push_back(i);
    }
    ll ans = 0;
    vector<ll> suf(n + 2), pref(n + 1);
    for (ll i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + (a[i - 1] == b[i - 1]);
    for (ll i = n; i > 0; i--)
        suf[i] = suf[i + 1] + (a[i - 1] == b[i - 1]);
    for (ll i = 1; i <= n; i++)
    {
        ans += pref[i] * (n - i);
        ans += suf[i] * (i - 1);
    }

    for (auto v : vals)
    {
        if (A[v].empty() || B[v].empty())
            continue;
        pB[v].push_back(0);
        ll S=0;
        for (auto x : B[v]){
            pB[v].push_back(pB[v].back() + x + 1);
            S+=n-x;
        }
        sB[v].push_back(S);
        for (auto x : B[v]){
            S-=n-x;
            sB[v].push_back(S);
        }
    }

    for (auto v : vals)
    {
        if (A[v].empty() || B[v].empty())
            continue;
        for (auto x : A[v])
        {
            ll L = min(x,n-x-1),R = max(n-x-1,x);
            auto ptL = upper_bound(B[v].begin(), B[v].end(), L)-B[v].begin(),
                 ptR = upper_bound(B[v].begin(), B[v].end(), R)-B[v].begin();
            ans+=pB[v][ptL];
            ans+=1LL*(L+1)*(ptR-ptL);
            ans+=sB[v][ptR];
        }
    }

    cout << ans << '\n';
}

int main()
{
    setIO("");
    ll t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}