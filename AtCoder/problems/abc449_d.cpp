#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7; // 998244353

ll cnt(int l, int r, int d, int u)
{
    int s = d + (abs(d) % 2);
    ll ret = 0;
    ll f = (0 <= r && 0 >= l && 0 <= u && 0 >= d);
    while (s <= u)
    {
        ret += max(0,min(abs(s)-1, r) - max(-abs(s)+1, l) + 1);
        s += 2;
    }
    s = l + (abs(l) % 2);
    while (s <= r)
    {
        ret += max(0,min(abs(s), u) - max(-abs(s), d) + 1);
        s += 2;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int L, R, D, U;
    cin >> L >> R >> D >> U;
    cout << cnt(L, R, D, U);

    return 0;
}