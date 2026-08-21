#include<bits/stdc++.h>
using namespace std;

void solve(){
    int m,k;
    cin>>m>>k;
    vector<int>ans;
    int s=0;
    
    for(int i=1;i<=k;i<<=1){
        if(k&i){
            ans.push_back((i<<1) - 1);
            s+=(i<<1) - 1;
        }
    }
    if(s>m){cout<<"-1\n";return;}
    m-=s;
    // if(m&1){cout<<"-1\n";return;}
    ans.push_back(m>>1);
    ans.push_back(m>>1);
    
    
    cout<<ans.size()<<'\n';
    for(auto x:ans)cout<<x<<' ';
    cout<<'\n';
}

int main(){
    int tc;cin>>tc;
    while(tc--){
        solve();
    }
}