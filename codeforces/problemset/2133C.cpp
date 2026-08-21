// problem link: https://codeforces.com/contest/2133/problem/C
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

int qry(int x, vector<int> &s)
{
    cout << "? " << x << " " << s.size() << " ";
    for (auto nd : s)
        cout << nd << ' ';
    cout << endl;
    int ans;
    cin >> ans;
    if(ans==-1)exit(0);
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> s(n);
    iota(s.begin(), s.end(), 1);
    vector<vector<int>> path(n + 1);
    for (int i = 1; i <= n; i++)
        path[qry(i, s)].push_back(i);
    int st = n;
    while (path[st].empty())
        st--;
    vector<int> res;
    res.push_back(path[st][0]);
    while (--st)
    {
        int u = res.back();
        for (int v : path[st])
        {
            vector<int> a{u, v};
            if (qry(u, a) == 2)
            {
                res.push_back(v);
                break;
            }
        }
    }
    cout << "! " << res.size() << ' ';
    for (auto x : res)
        cout << x << ' ';
    cout << '\n';
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}