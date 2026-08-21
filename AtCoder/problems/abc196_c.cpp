#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll n;
    cin>>n;
    int ans=0;
    int d=0;
    ll x=n;
    ll lim = 1;
    while (x)
    {
        d++;
        x/=10;
    }
    for (int i = 0; i < d/2; i++)
    {
        lim*=10;
    }
    
    ll mod = 1;
    for (ll i = 1; i <= lim; i++)
    {
        if(i%mod==0)mod*=10;
        if(i*(mod+1)<=n)ans++;
    }
    cout<<ans<<endl;

    return 0;

}