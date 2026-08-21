// problem link: https://atcoder.jp/contests/abc227/tasks/abc227_d
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
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll lo = 0, hi = 1e18/k;
    ll ans = 0;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        ll s=0;
        for (int i = 0; i < n; i++)
        {
            s+=min(mid,a[i]);
        }
        if(s>=mid*k){
            ans=mid;
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}