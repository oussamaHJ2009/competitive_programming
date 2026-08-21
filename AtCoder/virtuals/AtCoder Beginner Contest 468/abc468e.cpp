/*
*created: 2026-08-11 at 14:34:54
*problem: Sum of Average, link: https://atcoder.jp/contests/abc468/tasks/abc468_e
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll mod = 998244353;

ll binpow(ll a,ll b){
    a%=mod;
    ll res=1;
    while(b>0){
        if(b&1)res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}

ll Minv(ll a){
    return binpow(a,mod-2)%mod;
}

ll Mdiv(ll a,ll b){
    return (a*Minv(b))%mod;
}

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}