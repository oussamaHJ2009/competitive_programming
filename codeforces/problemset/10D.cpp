/*
 *created: 2026-07-30 at 09:22:37
 *problem: D. LCIS, link: https://codeforces.com/problemset/problem/10/D
 *author: a human
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<int> dp(m, 0), par(m, -1);
    for (int i = 0; i < n; i++)
    {
        int cur = 0, lst = -1;

        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j] && cur + 1 > dp[j])
            {
                dp[j] = cur + 1;
                par[j] = lst;
            }
            else if (a[i] > b[j] && dp[j] > cur)
            {
                cur = dp[j];
                lst = j;
            }
        }
    }

    int len = 0, pos = -1;
    for (int j = 0; j < m; j++)
    {
        if (dp[j] > len)
        {
            len = dp[j];
            pos = j;
        }
    }
    vector<int> lcis;
    while (pos != -1)
    {
        lcis.push_back(b[pos]);
        pos = par[pos];
    }
    reverse(lcis.begin(),lcis.end());
    cout << len << endl;
	for (int x : lcis) { cout << x << ' '; }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}