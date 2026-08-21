// problem link: https://codeforces.com/contest/2234/problem/F
// written by a rando

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int s = 0; s < n; s++)
    {
        vector<int> w(n);
        w[s] = 0;
        int mx = h[s];
        for (int i = 0; i < n - 1; i++)
        {
            if (h[(s + 1 + i) % n] >= mx)
            {
                w[(s + 1 + i) % n] = mx;
                mx = h[(s + 1 + i) % n];
            }
            else
            {
                w[(s + 1 + i) % n] = h[(s + 1 + i) % n];
            }
        }
        for (int i = n - 1; i > 1; i--)
        {
            if (w[(s + i + n) % n] > h[(s + i + n - 1) % n])
                w[(s + i + n - 1) % n] = w[(s + i + n) % n];
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += w[i];
        }
        cout << ans << ' ';
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}