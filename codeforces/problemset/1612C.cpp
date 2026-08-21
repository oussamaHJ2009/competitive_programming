#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin>>t;
    while (t--)
    {
        ll x,k;
        cin>>k>>x;
        ll ans=2*k-1;
        ll lo=1,hi=2*k-1;
        ll mid=0;
        while (lo<=hi)
        {
            mid=lo+(hi-lo)/2;
            ll f =0;
            if(mid>=k) f+=k*k - (((2*k-mid -1)*(2*k-mid))/2);
            else f= (mid*(mid+1))/2;
            if(f>=x){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
            
        }
        cout<<ans<<endl;
    }
    

    return 0;

}