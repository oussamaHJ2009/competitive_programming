// problem link: https://codeforces.com/contest/2240/problem/B
// written by a rando

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
const ull mod = 998244353;

ull binpow(ull a, ull b, ull m)
{
    a %= m;
    ull res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve()
{
    ull n, m, r, c;
    cin >> n >> m >> r >> c;
    ull x = ((((m - c) * (r - 1)) ) + (((n - r) * (c - 1)) ) + ((r * c) ) - 1);
    ull ans = binpow(2, x, mod);
    cout << ans << '\n';
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}



// 1000000000000000000-1
// 999999999999999999