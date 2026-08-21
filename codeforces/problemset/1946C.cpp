// problem link: https://codeforces.com/problemset/problem/1946/C
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

vector<vector<int>> T;
vector<int> d;
int cnt = 0;

void dfs(int u, int p, int x)
{
    d[u] = 1;
    for (auto v : T[u])
    {
        if (v != p)
        {
            dfs(v, u, x);
            d[u] += d[v];
        }
    }
    if (d[u] >= x)
    {
        d[u] = 0;
        cnt++;
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    T.assign(n, vector<int>());
    d.assign(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        T[a].push_back(b);
        T[b].push_back(a);
    }

    int lo = 0, hi = n / (k + 1);
    int ans = 0;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        cnt = 0;
        dfs(0, -1, mid);
        if (cnt > k)
        {
            lo = mid + 1;
            ans = mid;
        }
        else
            hi = mid - 1;
    }

    cout << ans << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}