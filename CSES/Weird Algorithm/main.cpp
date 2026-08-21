#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    ll n;
    cin >> n;
    while (n != 1)
    {
        cout << n << ' ';
        if (n & 1)
        {
            n *= 3;
            n++;
        }
        else
            n /= 2;
    }
    cout << 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}