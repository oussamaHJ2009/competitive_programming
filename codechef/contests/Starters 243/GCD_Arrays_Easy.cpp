//problem link: https://www.codechef.com/START243D/problems/GCDARR
//written by a rando


#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

using ll = int64_t;

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n,m;
    cin>>n>>m;
    ll ans=0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(gcd(i,j)!=1)continue;
            int cnt=0;
            for (int k = 1; k <= m; k++)
            {
                if(gcd(k,j)!=1 && gcd(k,i)!=1){
                    cnt++;
                }
            }
            ans=(ans+binpow(cnt,n-2,mod))%mod;
        }
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}