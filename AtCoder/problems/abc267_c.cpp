#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<ll>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    vector<ll> pref(n+1);
    vector<ll> ppref(n+1);
    pref[0]=0;
    ppref[0]=0;
    for (int i = 1; i <= n; i++)
    {
        pref[i]=a[i-1]+pref[i-1];
        ppref[i]=pref[i]+ppref[i-1];
    }
    ll ans=-1e18;
    for (int i = 0; i+m <= n; i++)
    {
        ll cur=m*pref[i+m]-ppref[i+m-1]+ppref[i]-pref[i];
        ans=max(ans,cur);
    }
    cout<<ans;

    return 0;

}