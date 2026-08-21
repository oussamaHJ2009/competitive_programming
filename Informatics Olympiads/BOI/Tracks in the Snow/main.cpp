#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Dr[4] = {-1,1,0,0};
ll Dc[4] = {0,0,-1,1};
const ll INF = 1e9;

void solve() {
    ll h,w;
    cin>>h>>w;
    vector<string>g(h,string(w,' '));
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            cin>>g[i][j];
        }
    }

    vector<vector<ll>>d(h,vector<ll>(w,INF));
    vector<vector<bool>>vis(h,vector<bool>(w,0));
    d[0][0]=1;
    vis[0][0]=1;

    auto in=[&](ll i,ll j){
        return (i<h && i>=0 && j<w && j>=0 && g[i][j]!='.');
    };

    deque<pair<ll,ll>>q;
    q.push_front({0,0});
    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop_front();
        for(ll i=0;i<4;i++){
            ll nr = Dr[i] + r, nc = Dc[i] + c;
            if(!in(nr,nc))continue;
            if(!vis[nr][nc]){
                vis[nr][nc]=1;
                if(g[r][c]==g[nr][nc])q.push_front({nr,nc});
                else q.push_back({nr,nc});
            }
            d[nr][nc] = min(d[nr][nc],d[r][c] + (g[r][c]!=g[nr][nc]));
        }
    }

    ll ans=0;
    for(ll i=0;i<h;i++)for(ll j=0;j<w;j++)if(d[i][j]!=INF)ans=max(ans,d[i][j]);
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}