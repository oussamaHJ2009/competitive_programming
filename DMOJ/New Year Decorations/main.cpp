#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7; // 998244353

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        ll lo = min(a, b), hi = max(a, b);
        ll cur = hi - hi % n + n;
        ll ans = ((lo / n) * (lo - lo % n + n + 2)) / 2 + (hi / n - lo / n) * (lo + 1) + ((a + b) / n - hi / n) * (hi + lo + 1) - (((a + b) / n - hi / n) * (cur + ((a + b) / n) * n)) / 2;

        cout << ans << endl;
    }

    return 0;
}