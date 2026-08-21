#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty())
    {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

using ll = int64_t;

ll solve(ll a, ll b)
{
    if (a == b)
        return 0;
    else if (a > b)
    {
        return 1 + (a & 1) + solve(a + (a & 1) >> 1, b);
    }
    else
    {
        return min(b - a, 1 + (b & 1) + solve(a, b >> 1));
    }
}

int main()
{
    setIO("");
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        cout << solve(a, b) << '\n';
    }
    return 0;
}