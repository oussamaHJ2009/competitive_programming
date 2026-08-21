#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<ll,ll>>>adj(n);
    while(m--){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a-1].push_back({b-1,c});
    }

    vector<priority_queue<ll>>d(n);
    
    d[0].push(0);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>>pq;
    pq.push({0,0});
    while (!pq.empty())
    {
        auto [dist,u] = pq.top();
        pq.pop();
        if(d[u].size()==k && dist>d[u].top())continue;
        for(auto [v,w]:adj[u]){
            if(d[v].size()<k || dist+w<d[v].top()){
                d[v].push(w+dist);
                while(d[v].size()>k)d[v].pop();
                pq.push({dist+w,v});
            }
        }
    }
    vector<ll>ans;
    while (!d[n-1].empty())
    {
        ans.push_back(d[n-1].top());
        d[n-1].pop();
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans){
        cout<<x<<' ';
    }
    cout<<'\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}