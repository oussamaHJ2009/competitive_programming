// problem link: https://atcoder.jp/contests/abc467/tasks/abc467_d
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

tuple<ll, ll, ll> get(ll x1, ll x2, ll y1, ll y2)
{
    ll a, b, c;
    a = 2 * (x2 - x1), b = 2 * (y2 - y1);
    c = - x2 * x2 - y2 * y2 + x1 * x1 + y1 * y1;
    ll g = gcd(a, gcd(c, b));
    a /= g, b /= g, c /= g;
    if (a < 0)
        a = -a, b = -b, c = -c;
    if (a == 0 && b < 0)
        b = -b, c = -c;
    return {a, b, c};
}

void solve()
{
    ll Px, Py, Qx, Qy, Rx, Ry, Sx, Sy;
    cin >> Px >> Py >> Qx >> Qy >> Rx >> Ry >> Sx >> Sy;
    auto [a1, b1, c1] = get(Px, Qx, Py, Qy);
    auto [a2, b2, c2] = get(Sx, Rx, Sy, Ry);
    if (a1 * b2 - a2 * b1 == 0)
        if (a1 == a2 && b1 == b2 && c1 == c2)
            cout << "Yes\n";
        else
            cout << "No\n";
    else
        cout << "Yes\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}