#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;
const ll mod = 1e9+7;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,ll>>>adj(n);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        adj[a].push_back({b,c});
    }

    vector<ll>d(n,INF),cnt(n,0),mn(n,INF),mx(n,-INF);
    d[0]=0;
    mn[0]=0;
    mx[0]=0;
    cnt[0]=1;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>>pq;
    pq.push({0,0});
    while (!pq.empty())
    {
        auto [dist,u] = pq.top();pq.pop();
        if(dist > d[u])continue;
        for(auto [v,w]:adj[u]){
            if(dist+w < d[v]){
                d[v] = dist+w;
                cnt[v] = cnt[u]%mod;
                mx[v] = mx[u] + 1;
                mn[v] = mn[u] + 1;
                pq.push({dist+w,v});
            }else if(dist+w==d[v]){
                (cnt[v] += cnt[u])%=mod;
                mx[v] = max(mx[v], mx[u] + 1);
                mn[v] = min(mn[v], mn[u] + 1);
            }
        }
    }
    
    cout<<d[n-1]<<' '<<cnt[n-1]<<' '<<mn[n-1]<<' '<<mx[n-1]<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}