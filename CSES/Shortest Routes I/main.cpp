#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,ll>>>adj(n);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a-1].push_back({b-1,c});
    }

    vector<ll>d(n,1e18);
    d[0]=0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>>pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto [len,u] = pq.top();
        pq.pop();
        if(d[u]<len)continue;
        for(auto [v,w]:adj[u]){
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                pq.push({d[v],v});
            }
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<d[i]<<' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}