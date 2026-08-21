// problem link: https://codeforces.com/contest/1954/problem/D
// authored by a[i] human (i guess?)

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

const int mod = 998244353;
const int N = 5001;
vector<ll> dp(N, 0);

void solve()
{
    int n;
    cin >> n;
    dp[0] = 1;
    vector<int> a(n);
    vector<int> cnt(N, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        for (int j = N - 1; j >= a[i]; j--)
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
    }
    ll ans = 0;
    for (int i = 1; i < N; i++)
        ans = (ans + ((i + 1) / 2) * (dp[i] - cnt[i]) + (i * cnt[i])) % mod;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < a[i] - 1; j++)
        {
            ll c = (a[i] - (j + a[i] + 1) / 2) * dp[j];
            ans = (ans + c) % mod;
        }
    }

    cout << ans << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}