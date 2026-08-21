#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll K;
    cin>>K;
    ll cnt=1;
    bool prime=true;
    for (ll i = 2; i*i <= K && prime; i++)
    {
        if(K%i==0)prime=false;
    }
    
    ll ans=K;
    for (int i = 2; i <= 30 && !prime; i++)
    {
        cnt*=i;
        if(cnt%K==0){
            ans=i;
            break;
        }
    }
    cout<<ans<<"\n";

    return 0;

}