#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        ll n,x1,x2,k;
        cin>>n>>x1>>x2>>k;
        if(n<=3){
            cout<<1<<'\n';
            continue;
        }
        x1--;x2--;
        ll D=min((x1-x2+n)%n,(x2-x1+n)%n);
        ll ans=D+k;
        cout<<ans<<'\n';
    }

    return 0;
}