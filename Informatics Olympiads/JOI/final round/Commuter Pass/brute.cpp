#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;

void dijk(int s, vector<vector<pair<int,ll>>>&adj, vector<ll>&d){
    d[s]=0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>>pq;
    pq.push({0LL,s});
    while (!pq.empty())
    {
        auto [dist, u] = pq.top();
        pq.pop();
        if(dist>d[u])continue;
    
        for(auto [v,w]:adj[u]){
            if(d[v] > dist + w){
                d[v] = dist + w;
                pq.push({d[v],v});
            }
        }
    }
}

void solve() {
    int N,M,S,T,U,V;
    cin>>N>>M>>S>>T>>U>>V;
    S--,T--,U--,V--;
    vector<vector<pair<int,ll>>> adj(N);
    while(M--){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    vector<vector<ll>>dist(N,vector<ll>(N,INF));
    for(int i=0;i<N;i++){
        dijk(i, adj, dist[i]);
    }

    ll sp = dist[S][T];
    ll ans = dist[U][V];

    for(int u = 0;u < N; u++){
        for(int v = 0;v<N;v++){
            if(dist[u][v] + dist[S][u] + dist[T][v] == sp){
                ans = min({ans, dist[U][u] + dist[V][v], dist[U][v] + dist[V][u]});
            }
        }
    }

    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}