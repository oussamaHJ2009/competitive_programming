// problem link: https://atcoder.jp/contests/abc460/tasks/abc460_e
// written by a rando

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
using ull = unsigned long long;
const int mod = 998244353;

vector<ull> p10(20);
void solve()
{
    ll N;
    ll M;
    cin >> N >> M;
    ll ans = 0;
    int D = 0;
    while (p10[D] <= N)
        D++;
    for (int d = 1; d <= D; d++)
    {
        ull g = gcd(p10[d] - 1, M);
        ans = (ans + ((min(ull(N + 1), p10[d]) - p10[d - 1]) % mod) * ((N / (M / g)) % mod)) % mod;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    p10[0] = 1;
    for (int i = 1; i <= 19; i++)
        p10[i] = p10[i - 1] * 10;
    while (t--)
    {
        solve();
    }

    return 0;
}