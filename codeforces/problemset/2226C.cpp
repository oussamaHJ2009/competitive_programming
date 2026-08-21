#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=2*1e5+5;
void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int &it:a)cin>>it;
    sort(a.begin(),a.end());
    int lo=0,hi=n;
    int ans=0;
    int mid;
    while (lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        int mex=0;
        vector<int>cnt(mid,0);
        for (int i = 0; i < n; i++)
        {
            if(a[i]<mid)cnt[a[i]]++;
        }
        while (mex<mid && cnt[mex])mex++;
        for(auto x:a){
            if(x>=mid || (x<mid &&  cnt[x]>1)){
                if((x-1)/2>=mex){
                    if(x<mid)cnt[x]--;
                    if(mex<mid)cnt[mex]++;
                    while (mex<mid && cnt[mex])mex++;
                }
            }
        }
        
        if(mex>=mid){
            lo=mid+1;
            ans=mid;
        }else{
            hi=mid-1;
        }
    }
    cout<<ans<<'\n';
}

int main(){
    int t;cin>>t;
    while (t--)
    {
        solve();
    }
    
}