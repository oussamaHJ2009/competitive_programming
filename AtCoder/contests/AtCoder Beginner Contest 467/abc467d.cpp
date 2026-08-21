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

void solve()
{
    ll Px, Py, Qx, Qy, Rx, Ry, Sx, Sy;
    cin >> Px >> Py >> Qx >> Qy >> Rx >> Ry >> Sx >> Sy;
    ll a1 = Px - Qx, b1 = Py - Qy, a2 = Rx - Sx, b2 = Ry - Sy;
    ll det = a1 * b2 - a2 * b1;
    if (det)
        cout << "Yes\n";
    else
        cout << "No\n";
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