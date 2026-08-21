// problem link: https://codeforces.com/problemset/problem/2245/E
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
    vector<vector<int>> T(n);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        T[a].push_back(b);
        T[b].push_back(a);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (T[i].size() % 2 == 0)
            continue;
        for (auto u : T[i])
        {
            if (T[u].size() % 2)
                ans++;
        }
    }
    ans /= 2;
    vector<bool> v(n, false);
    for (int i = 0; i < n; i++)
    {
        if (T[i].size() % 2 == 0 && !v[i])
        {
            queue<int> q;
            ll cnt = 0;
            q.push(i);
            v[i] = 1;
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (auto u : T[cur])
                {
                    if (!v[u] && T[u].size() % 2 == 0)
                    {
                        v[u] = 1;
                        q.push(u);
                    }
                    else if (T[u].size() % 2)
                    {
                        cnt++;
                    }
                }
            }
            ans += (cnt * (cnt - 1)) / 2;
        }
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