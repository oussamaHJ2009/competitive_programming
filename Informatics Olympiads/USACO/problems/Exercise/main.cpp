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
    vector<int> p;
    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
    {
        bool prime = 1;
        for (int j = 2; j * j <= i; j++)
            if (i % j == 0)
                prime = 0;
        if (prime)
            p.push_back(i);
    }

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (auto x : p)
    {
        for (int i = n; i >= 0; i--)
        {
            int v = x;
            while (v <= n)
            {
                if (i >= v)
                    dp[i] = (dp[i] + (dp[i - v] * v) % m) % m;
                v = (v * x) % m;
            }
        }
    }

    long long ans=0;
    for (int i = 0; i <= n; i++)
    {
        ans=(ans+dp[i])%m;
    }
    cout<<ans<<'\n';
}

int main()
{
    setIO("exercise");
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
