/* stuff you should look for
 *  int overflow, array bounds
 *  special cases (n=1?)
 *  do smth instead of nothing and stay organized
 *  WRITE STUFF DOWN
 *  DON'T GET STUCK ON ONE APPROACH
 */
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const int N = 21;
const int mod = 1e9 + 7;
int a[N]{0};
int dp[N + 1][1 << N]{0};

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            a[i] |= x << j;
        }
    }
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int b = 0; b < (1 << n); b++)
        {
            if (__builtin_popcount(b) != i)
                continue;
            for (int j = 0; j < n; j++)
            {
                if ((a[i - 1] >> j) & 1 && (b >> j) & 1)
                    dp[i][b] = (dp[i][b] + dp[i - 1][b ^ (1 << j)]) % mod;
            }
        }
    }

    cout << dp[n][(1 << n) - 1] << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0), solve();
    return 0;
}