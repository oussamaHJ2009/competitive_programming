/* stuff you should look for
 *  int overflow, array bounds
 *  special cases (n=1?)
 *  do smth instead of nothing and stay organized
 *  WRITE STUFF DOWN
 *  DON'T GET STUCK ON ONE APPROACH
 */
#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty())
    {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> tab(n, vector<int>(n));
    vector<int> cnt(2 * n + 1, 0), must(2 * n + 1, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> tab[i][j], cnt[tab[i][j]]++;
    must[2] = 1;
    for (int i = 3; i <= 2 * n + 1; i++)
        must[i] = must[i - 1] + (i <= n + 1 ? 1 : -1);
    
    
}

int main()
{
    setIO("");
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}