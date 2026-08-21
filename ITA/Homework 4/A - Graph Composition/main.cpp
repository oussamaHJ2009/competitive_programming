#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>>G,F;
vector<int>Gc,Fc;
int Gcc=0,Fcc=0;

void dfs(int u,vector<int>&col,vector<vector<int>>&adj,int cnt){
    if(col[u]!=-1)return;
    col[u]=cnt;
    for(int v:adj[u]){
        dfs(v,col,adj,cnt);
    }
}

void solve() {
    int n,m1,m2;
    cin>>n>>m1>>m2;
    G.assign(n,vector<int>());
    F.assign(n,vector<int>());
    Gc.assign(n,-1);
    Fc.assign(n,-1);
    Gcc=0;Fcc=0;
    vector<pair<int,int>>Fe(m1);
    while(m1--){
        cin>>Fe[m1].first>>Fe[m1].second;
    }
    while(m2--){
        int a,b;cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i=0;i<n;i++){
        if(Gc[i]==-1){
            dfs(i,Gc,G,Gcc);
            Gcc++;
        }
    }

    int ans=0;

    for(auto [u,v]:Fe){
        u--,v--;
        if(Gc[u]!=Gc[v])ans++;
        else {
            F[u].push_back(v);
            F[v].push_back(u);
        }
    }

    for(int i=0;i<n;i++){
        if(Fc[i]==-1){
            dfs(i,Fc,F,Fcc);
            Fcc++;
        }
    }

    ans+=Fcc-Gcc;

    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--)
       solve();
    return 0;
}