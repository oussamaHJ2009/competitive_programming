#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll lo=*max_element(a.begin(),a.end()),hi=accumulate(a.begin(),a.end(),0LL);
    ll ans=lo;
    while (lo<=hi)
    {
        ll mid=lo+(hi-lo)/2;
        ll cnt=0;
        ll cur=0;
        bool ok =true;
        for (int i = 0; i < n; i++)
        {
            if(a[i]>mid){ok=false;break;}
            if(cur+a[i]>mid){
                cnt++;
                cur=0;
            }
            cur+=a[i];
        }
        if(cur>0)cnt++;
        if(cnt<=k && ok){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
        
    }
    cout<<ans;
    return 0;

}