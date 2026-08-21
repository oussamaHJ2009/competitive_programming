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
    auto f = [&](ll x){
        ll res=0;
        for (int i = 1; i <= n; i++)
        {
            res+=min(x/i,n);
        }
        return res;
    };
    ll lo=1,hi=n*n;
    ll ans=0;
    while (lo<=hi)
    {
        ll mid = lo+(hi-lo)/2;
        if(f(mid)>=(n*n+1)/2){
            hi=mid-1;
            ans=mid;
        }else{
            lo=mid+1;
        }
    }
    cout<<ans;

    return 0;

}