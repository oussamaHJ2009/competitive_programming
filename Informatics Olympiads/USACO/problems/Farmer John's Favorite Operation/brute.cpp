#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve() {
    int n;
    ll m;
    cin>>n>>m;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=1e18;

    for (int j=0;j<n;j++)
    {
        ll x=a[j]%m;
        ll mn=0;
        for (int i = 0; i < n; i++)
        {
            mn+=min({abs(x-(a[i]%m)),abs(x-m-(a[i]%m)),abs(x+m-(a[i]%m))});
        }
        ans=min(mn,ans);
    }
    cout<<ans<<'\n';
}

int main() {
    setIO("");
    int t = 1;
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}