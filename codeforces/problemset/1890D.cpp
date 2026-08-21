// problem link: https://codeforces.com/problemset/problem/1890/D
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

void solve()
{
    int n;
    ll c;
    cin >> n >> c;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<bool> v(n, 0);
    int l = 1;
    ll s = a[0];
    for (int i = 1; i < n; i++)
    {
        if (s + a[i] >= (i + 1) * c && !v[i])
        {
            v[i] = 1;
            s += a[i];
        }
        while (l < n && (s + a[l] >= (l + 1) * c || v[l]))
        {
            if (!v[l])
            {
                s += a[l];
                v[l] = 1;
            }
            l++;
        }
    }
    if (l < n)
        cout << "No\n";
    else
        cout << "Yes\n";
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