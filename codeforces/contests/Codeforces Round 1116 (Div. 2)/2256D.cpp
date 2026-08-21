/*
*created: 2026-08-09 at 15:35:25
*problem: D. A Ribbon for Tomorrow, link: https://codeforces.com/contest/2256/problem/D
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 998244353;

const ll N = 1000005;

ll f[N];

ll bpow(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll Minv(ll a){
    return bpow(a,mod-2)%mod;
}

ll C(ll n,ll k){
    if (k < 0 || k > n) return 0;
    ll bot = (f[k]*f[n-k])%mod;
    return (f[n] * Minv(bot))%mod;
}

void solve() {
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll>sz;
    ll cur=1;
    for(ll i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            sz.push_back(cur);
            cur=1;
        }else cur++;
    }
    sz.push_back(cur);
    ll cnt[2]{0,0},sum[2]{0,0};
    for(ll i=0;i<sz.size();i++){
        sum[i&1]+=sz[i]-1;
        cnt[i&1]++;
    }

    ll x1 = C(sum[0]+cnt[0]-1,cnt[0]-1)%mod;
    ll x2 = C(sum[1]+cnt[1]-1,cnt[1]-1)%mod;

    ll ans = (sz.size()==1?1:(x1*x2)%mod);

    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    f[0]=1;
    for(ll i=1;i<N;i++)f[i]=(f[i-1]*i)%mod;
    ll t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}