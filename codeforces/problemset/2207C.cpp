#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve(){
    int n;
    ll h;
    cin>>n>>h;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<ll>v(n);
    for(int i=0;i<n;i++){
        int r=i+1,l=i-1;
        ll mx=a[i];
        v[i]=h-a[i];
        while (r<n)
        {
            mx=max(mx,a[r]);
            v[i]+=h-mx;
            r++;
        }
        mx=a[i];
        while (l>=0)
        {
            mx=max(mx,a[l]);
            v[i]+=h-mx;
            l--;
        }
    }
    ll ans=0;
    for (int i = 0; i < n; i++)
    {
        int idx=i;
        for (int j = i; j < n; j++)
        {
            if(a[j]>=a[idx])idx=j;
            ans=max(ans,v[i]+v[j]-v[idx]);
        }
        
    }
    cout<<ans<<'\n';
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
}
