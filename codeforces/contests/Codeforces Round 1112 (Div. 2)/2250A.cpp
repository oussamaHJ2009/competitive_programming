// problem link: https://codeforces.com/contest/2250/problem/A
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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n % 2)
    {
        cout << "NO\n";
        return;
    }
    int mn = 1e9, mx = 0;
    for (int i = 0; i < n - 1; i += 2)
    {
        mn = min(a[i], mn);
        mx = max(mx, a[i + 1]);
        if (mn - mx <= 1 || a[i] - a[i + 1] <= 1)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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