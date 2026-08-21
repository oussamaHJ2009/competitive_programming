// problem link: https://codeforces.com/contest/2121/problem/F
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

ll s, x;
ll cnt(vector<ll> &a, int l, int r)
{
    if (l + 1 > r - 1)
        return 0;
    l++;
    map<ll, int> p;
    map<pair<ll, int>, int> frq;
    p[0] = 1;
    frq[{0, 0}] = 1;
    int c = 0;
    ll sum = 0;
    ll total = 0, minus = 0;
    for (int i = l; i < r; i++)
    {
        sum += a[i], c += (a[i] == x);
        total += p[sum - s];
        minus += frq[{sum - s, c}];
        p[sum]++;
        frq[{sum, c}]++;
    }

    return total - minus;
}

void solve()
{
    int n;
    cin >> n >> s >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pair<int, int>> interval;
    int lst = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > x)
        {
            interval.push_back({lst, i});
            lst = i;
        }
    }
    interval.push_back({lst,n});

    ll ans = 0;
    for (auto [l,r]:interval)
    {
        ans+=cnt(a,l,r);
    }
    
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}