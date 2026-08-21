// problem link: https://codeforces.com/contest/1201/problem/C
// written by a rando

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll lo = a[n / 2], hi = a[n / 2] + k;
    while (hi - lo > 1)
    {
        ll mid = lo + (hi - lo) / 2;
        ll cnt = 0;
        for (int i = n / 2; i < n; i++)
        {
            if (a[i] < mid)
                cnt += mid - a[i];
        }
        if (cnt <= k)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    ll cnt = 0;
    for (int i = n / 2; i < n; i++)
    {
        if (a[i] < hi)
            cnt += hi - a[i];
    }
    if (cnt <= k)
    {
        cout << hi << '\n';
    }
    else
    {
        cout << lo << '\n';
    }
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