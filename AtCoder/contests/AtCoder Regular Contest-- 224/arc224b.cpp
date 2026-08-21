// problem link: https://atcoder.jp/contests/arc224/tasks/arc224_b
// authored by a human (i guess?)

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    ll n;
    cin >> n;
    ll k = (ll)sqrt(n);
    while(k*k<n){k++;}
    while(k*k>=n){k--;}
    ll x = n - (k * k);ll k = (ll)sqrt(n);
    while(k*k<n){k++;}
    while(k*k>=n){k--;}
    ll ans = 2 * k * (k - 1);
    if(x>0)ans += 2 * min(x, k) - 1;
    if (x > k)
        ans += 2 * (x - k) - 1;
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}