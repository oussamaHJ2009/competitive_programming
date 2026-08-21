#include <bits/stdc++.h>
using ll = int64_t;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        ll s = 0;
        ll ans = 2e18;

        for (int i = 0; i < n; ++i)
        {
            s += a[i];
            ll cur = s / (i + 1);
            ans = min(ans, cur);

            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}