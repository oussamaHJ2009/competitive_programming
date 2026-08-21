#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        ll a,b,n;
        cin>>n>>a>>b;
        ll ans=0;
        if(3*a<b){
            ans=n*a;
        }else{
            ans=(n/3)*b;
            ans+=min((n%3)*a,b);
        }
        cout<<ans<<'\n';
    }

    return 0;

}