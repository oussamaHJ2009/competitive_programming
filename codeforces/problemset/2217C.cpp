#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        ll n,m,a,b;
        cin>>n>>m>>a>>b;
        if(gcd(a,n)==1 && gcd(b,m)==1 && gcd(n,m)<=2)cout<<"YES\n";
        else cout<<"NO\n";
        
    }

    return 0;

}