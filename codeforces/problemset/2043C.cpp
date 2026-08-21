// problem link: https://codeforces.com/contest/2043/problem/C
// authored by a human (i guess?)

/* stuff you should look for
 * ll overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

pair<ll, ll> get(vector<ll> &a, ll l, ll r)
{
    ll lo = 0, hi = 0;
    ll mn=0,mx=0,p=0;
    for (ll i = l; i < r; i++)
    {
        p+=a[i];
        hi=max(p-mn,hi);
        lo=min(p-mx,lo);
        mn=min(mn,p);
        mx=max(mx,p);
    }

    return {lo, hi};
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll xi = -1;
    for (ll i = 0; i < n; i++)
        if (a[i] != -1 && a[i] != 1)
            xi = i;
    vector<ll> ans;
    if (xi == -1)
    {
        auto [lo, hi] = get(a, 0, n);
        for (ll val = lo; val <= hi; val++)
            ans.push_back(val);
    }
    else
    {
        pair<ll, ll> p1{0, 0}, p2{0, 0};
        if (xi > 0)
            p1 = get(a, 0, xi);
        if (xi + 1 < n)
            p2 = get(a, xi + 1, n);
        ll lo = min(p1.first, p2.first);
        ll hi = max(p1.second, p2.second);
        ll r1 = 0, r2 = 0, l1 = 0, l2 = 0;
        ll s = 0;
        for (ll i = xi - 1; i >= 0; i--)
        {
            s += a[i];
            r1 = max(r1, s);
            l1 = min(l1, s);
        }
        s = 0;
        for (ll i = xi + 1; i < n; i++)
        {
            s += a[i];
            r2 = max(r2, s);
            l2 = min(l2, s);
        }
        ll rf = a[xi] + r1 + r2;
        ll lf = a[xi] + l1 + l2;
        for (ll i = lf; i <= rf; i++)
            ans.push_back(i);
        for (ll i = lo; i <= hi; i++)
            ans.push_back(i);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << '\n';
    for (auto x : ans)
    {
        cout << x << ' ';
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}