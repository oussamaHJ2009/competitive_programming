#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    map<ll,int>cnt1;
    map<ll,ll>cnt2;
    map<ll,bool>v;
    unordered_set<int>cnt;
    for (int i = 0; i < n; i++)
    {
        ll x=a[i];
        if(i==0){
            int r=0;
            if(x==1){
                cnt1[2]++;
                cnt2[2]++;
                cnt.insert(2);
            }
            cnt1[x]++;
            cnt.insert(x);
            while (x!=1)
            {
                x = (x % 2) ? x + 1 : x / 2;
                r++;
                cnt1[x]++;
                cnt2[x]+=r;
                cnt.insert(x);
            }
        }else{
            if(x==1 && cnt.find(2)!=cnt.end()){
                cnt1[2]++;
                cnt2[2]++;
            }
            if(cnt.find(x)!=cnt.end()){
                cnt1[x]++;
            }
            int r=0;
            while (x!=1)
            {
                x = (x % 2) ? x + 1 : x / 2;
                r++;
                if(cnt.find(x)!=cnt.end()){
                    cnt1[x]++;
                    cnt2[x]+=r;
                }
            }
            
        }
    }
    
    ll ans=1e18;
    for (auto x:cnt)
    {
        if(cnt1[x]==n)ans=min(ans,cnt2[x]);
    }
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while (t--)
    {
        solve();
    }
    
}