#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>adj(n);
    while(m--){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a-1].push_back({b-1, c});
    }

    vector<vector<ll>>d(2,vector<ll>(n,1e18));
    priority_queue<tuple<ll,ll,bool>, vector<tuple<ll,ll,bool>>, greater<tuple<ll,ll,bool>>>pq;
    pq.push({0,0,0});
    d[0][0]=0;
    d[1][0]=0;
    while(!pq.empty()){
        auto [len,u,c] = pq.top();pq.pop();
        
        if(len > d[c][u])continue;
        for(auto [v,w]:adj[u]){
            if(len + w < d[c][v]){
                d[c][v] = len + w;
                pq.push({d[c][v],v,c});
            }
            if(c)continue;
            if(len + w/2 < d[1][v]){
                d[1][v] = len + w/2;
                pq.push({d[1][v],v,true});
            }
        }
    }

    cout<<d[1][n-1]<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}