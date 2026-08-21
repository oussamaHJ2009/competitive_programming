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
        ll x;
        cin>>n>>x;
        vector<ll>a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        int lo=*min_element(a.begin(),a.end()),hi=lo+x+1;
        int ans=0;
        while (lo<=hi)
        {
            ll mid=lo+(hi-lo)/2;
            ll s=0;
            for (int i = 0; i < n; i++)
            {
                s+=max(0LL,mid-a[i]);
            }
            if(s<=x){
                lo=mid+1;
                ans=mid;
            }else{
                hi=mid-1;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;

}