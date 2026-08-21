#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int N,A,B;
    cin>>N>>A>>B;
    map<int,int>cnt;
    while(N--){
        int id,n;
        cin>>n>>id;
        cnt[id]=n;
    }
    
    stack<int>cand;
    map<int,set<int>>g;
    for(auto [id,_]:cnt){
        g[id]={};
        cand.push(id);
        for(auto X:{A,B}){
            if(cnt.count(X-id))g[id].insert(X-id);
        }
    }

    ll ans=0;
    while(!cand.empty()){
        int u = cand.top();
        cand.pop();
        if(g[u].size()!=1)continue;
        int v = *g[u].begin();
        if(u==v){
            ans+=cnt[u]/2;
        }else{
            int inc = min(cnt[u],cnt[v]);
            ans+=inc;
            cnt[v]-=inc;
        }
        g[u].erase(v);
        g[v].erase(u);
        cand.push(v);
    }

    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}