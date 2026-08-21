// problem link: https://atcoder.jp/contests/arc225/tasks/arc225_a
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

int M[5]{0, 2, 4, 1, 3};
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> X(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> X[i][j], X[i][j] = M[X[i][j]], cout << X[i][j] << ' ';
        }
        cout<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}