#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, w;
    cin>>n>>w;
    vector<pair<ll,ll>> a(n);
    for (int i = 0; i < n; i++){cin>>a[i].first>>a[i].second;}
    sort(a.begin(),a.end(),greater<pair<ll,ll>>());
    
    ll ans=0,cw=0;
    ll i = 0;
    for (;i<n;i++)
    {
        if(w-cw>=a[i].second){ans+=a[i].second*a[i].first;cw+=a[i].second;}
        else{break;}
    }
    if(i<n)ans+=a[i].first*(w-cw);
    cout<<ans<<endl;
    return 0;
}