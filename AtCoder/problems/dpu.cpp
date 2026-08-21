// problem link: https://atcoder.jp/contests/dp/tasks/dp_u
// authored by a human (i guess?)

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON't GET STUCK ON ONE APPROACH
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 16;
int a[N][N]{0};
ll dp[1 << N]{0};

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int s = 0; s < (1 << n); s++)
    {
        dp[s]=0;
        for (int i = 0; i < n; i++)
        {
            if(!((s>>i) & 1))continue;
            for (int j = 0; j < i; j++)
            {
                if(!((s>>j) & 1))continue;
                dp[s] += a[i][j];
            }
            
        }
        
    }

    for (int s = 0; s < (1 << n); s++)
    {
        for (int t = s; t != 0; t = (t - 1) & s)
        {
            dp[s] = max(dp[s], dp[t] + dp[s ^ t]);
        }
    }

    cout<<dp[(1<<n) - 1]<<'\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0), solve();
    return 0;
}