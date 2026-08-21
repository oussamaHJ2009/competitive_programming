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
    ll maxa = (int)1e5;
    ll maxb = 34;
    ll ans = 0;
    map<ll,ll>cnt;
    for (ll a = 2; a <= maxa; a++)
    {
        for (ll b = 2; b <= maxb; b++)
        {
            ll c = (ll)pow(a,b);
            if(c>n)break;
            if(c<=n && !cnt[c]){cnt[c]++;ans++;}
        }
        
    }
    cout<<n-ans;

    return 0;

}