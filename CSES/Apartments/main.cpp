#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int p1 = 0, p2 = 0;
    ll ans = 0;
    while (p1 < n && p2 < m)
    {
        if (abs(b[p2] - a[p1]) <= k)
        {
            p1++;
            p2++;
            ans++;
        }
        else
        {
            if (p2 < m && a[p1] < b[p2])
                p1++;
            else
                p2++;
        }
    }
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