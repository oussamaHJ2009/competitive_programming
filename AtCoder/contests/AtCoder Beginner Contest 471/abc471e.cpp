/*
*created: 2026-08-15 at 13:00:06
*problem: Sum of Square of Sum, link: http
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int maxN = 200001;

const ll MOD = 998244353;

struct Combinatorics {
    vector<ll> fact, invFact;

    Combinatorics(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);
        
        fact[0] = 1;
        invFact[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        
        invFact[n] = power(fact[n], MOD - 2);
        
        for (int i = n - 1; i >= 1; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }

    ll power(ll base, ll exp) {
        ll res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    
    ll nCr(int n, int k) {
        if (k < 0 || k > n) return 0;
        ll num = fact[n];
        ll den = (invFact[k] * invFact[n - k]) % MOD;
        return (num * den) % MOD;
    }
};

void solve() {
    int n, k;
    cin>>n>>k;
    Combinatorics cb(n);
    vector<ll> a(n);
    ll ans = 0;
    ll S=0;
    ll Sq=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        (Sq+=(a[i]*a[i])%MOD)%=MOD;
        (S+=a[i])%=MOD;
    }
    (S*=S)%=MOD;
    S-=Sq;
    if(S<0)S+=MOD;
    Sq= (Sq*cb.nCr(n-1,k-1))%MOD;
    S= (S*cb.nCr(n-2,k-2))%MOD;
    (ans+=(S+Sq)%MOD)%=MOD;
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}