#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    ll ans=0;
    for (int i = 0; i < n; i++)
    {
        ans+=max(a[(i+1)%n],a[i]);
    }
    ans-=*max_element(a.begin(),a.end());
    cout<<ans<<'\n';
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