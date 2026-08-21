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
    ll cu=1;
    ll ans=0;
    for (;cu*cu*cu<=n;cu++)
    {
        for (ll b = cu; b <= n/(cu*b); b++)
        {
            ans+=1+n/(cu*b)-b;
        }
    }
    cout<<ans<<endl;

    return 0;

}