// problem link: https://codeforces.com/contest/2247/problem/C
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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<int> c(2, 0);

    for (int i = 0; i < n; i++)
        c[a[i]] += (a[i] != b[i]);

    if (c[0] > 0 && c[1] == 0)
    {
        bool a1 = 0, b0 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
                a1 = 1;
            if (b[i] == 0)
                b0 = 1;
        }

        if (a1 && b0)
            cout << "2\n";
        else
            cout << "-1\n";
    }
    else if (c[1] == 0 && c[0] == 0)
        cout << "0\n";
    else if (c[1] % 2 == 0)
        cout << "2\n";
    else
        cout << "1\n";
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