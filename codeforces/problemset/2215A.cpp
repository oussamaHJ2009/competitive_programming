#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,p,q;
        cin>>n>>k>>p>>q;
        vector<ll>a(n);
        vector<ll>pre(n+1,0),suf(n+1,0);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            pre[i+1]=pre[i]+min(a[i]%p,(a[i]%q)%p);
        }
        for (int i = n-1; i > 0; i--)
        {
            suf[i]=suf[i+1]+min(a[i]%p,(a[i]%q)%p);
        }
        vector<ll>mdp(n),mdqp(n);
        for (int i = 0; i < n; i++)
        {
            mdp[i]=a[i]%p;
            mdqp[i]=(a[i]%q)%p;
        }
        for (int i = 1; i < n; i++)
        {
            mdp[i]+=mdp[i-1];
            mdqp[i]+=mdqp[i-1];
        }
        int l=0,r=k;
        ll ans=min({mdp[k-1],mdqp[k-1]})+suf[k];
        while (r<n)
        {
            ll s=min(mdp[r]-mdp[l],mdqp[r]-mdqp[l])+pre[l+1]+suf[r+1];
            ans=min(ans,s);
            r++;l++;
        }
        cout<<ans<<'\n';
    }
}