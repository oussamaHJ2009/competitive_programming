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
        int n;
        cin >> n;
        ll ans = 0;
        vector<ll> a(n);
        for (auto &it : a)
        {
            cin >> it;
        }
        //;
        vector<ll> s(n);
        s[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            s[i] = min(s[i + 1], a[i]);
            ans += a[i] - s[i];
        }
        ll cur = 0;
        ll best = -1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i - 1]) cur++;
            else {
                best = max(best, cur);
                cur = 0;
            }
        }
        best = max(best, cur);
        cout << ans + best << "\n";
    }

    return 0;
}