#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>c(n);
        ll ans=0;
        for (int i = 0; i < n; i++)
        {
            cin>>c[i];
            if(c[i]%2)ans=1;
        }
        for (int i = 0; i < n; i++)
        {
            ans+=(c[i]/2)*2;
        }
        cout<<ans<<'\n';
    }

    return 0;

}