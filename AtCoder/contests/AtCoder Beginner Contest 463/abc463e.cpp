//problem link: https://atcoder.jp/contests/abc463/tasks/abc463_d
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const ll INF = 1e18;
vector<vector<pair<ll, ll>>> adj;
ll n,m,y;
vector<ll>d;
vector<ll>x;

void dijkstra(ll s, vector<ll> & d) {
    ll n = adj.size();
    d.assign(n, INF);
    vector<ll> p(n, -1);

    d[s] = 0;
    set<pair<ll, ll>> q;
    q.insert({0, s});
    while (!q.empty()) {
        ll v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
        
    }
}

void solve() {
    cin>>n>>m>>y;
    adj.assign(n+1,vector<pair<ll,ll>>());
    for (ll i = 0; i < m; i++)
    {
        ll u,v,T;
        cin>>u>>v>>T;
        u--;v--;
        adj[u].push_back({v,T});
        adj[v].push_back({u,T});
    }
    x.assign(n,0);
    for (ll i = 0; i < n; i++)
    {
        cin>>x[i];
        adj[n].push_back({i,x[i]+y});
        adj[i].push_back({n,x[i]});
    }

    dijkstra(0,d);



    for (ll i = 1; i < n; i++)
    {
        cout<<min(d[i],x[0]+x[i]+y)<<' ';
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}