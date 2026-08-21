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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = i + 1;
    }
    vector<int> l(m), r(m);

    for (int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i];
        l[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << "\n\n";
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < m; j++)
        {
            reverse(ans.begin() + l[j], ans.begin() + r[j]);
            bool match=true;
            for (int i = 0; i < n; i++)
            {
                cout << ans[i] << ' ';
                if(ans[i]!=i+1)match=0;
            }
            if(match)cout<<"match\n";
            cout << '\n';
        }
        cout<<'\n';
    }
}

int main()
{
    // setIO("swap");
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}