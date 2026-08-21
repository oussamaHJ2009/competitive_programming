// problem link: https://codeforces.com/contest/2250/problem/B
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
    int n, k;
    cin >> n >> k;
    string s = "";
    if (k > (n / 2 - 1 + (n + 1) / 2 - 1))
    {
        cout << "-1\n";
        return;
    }
    int c = 0;
    for (int i = 0; i <= k / 2; i++)
    {
        s += '0';
        c++;
    }
    for (int i = 0; i <= (k + 1) / 2; i++)
    {
        s += '1';
        c++;
    }
    int ch=0;
    while (c < n)
    {
        s += ch+'0';
        ch++;ch%=2;
        c++;
    }
    cout << s << '\n';
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