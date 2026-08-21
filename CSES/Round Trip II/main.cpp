#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>>adj;
vector<int>state,par;
int st=-1,ed=-1;

bool dfs(int u){
    state[u]=1;
    for(int v:adj[u]){
        if(state[v]==0){
            par[v]=u;
            if(dfs(v))return true;
        }else if(state[v]==1){
            st = v,ed = u;
            return true;
        }
    }
    state[u]=2;
    return false;
}

void solve() {
    int n,m;
    cin>>n>>m;
    adj.assign(n,vector<int>());
    state.assign(n,0);
    par.assign(n,-1);

    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
    }

    for(int i=0;i<n;i++){
        if(state[i]==0 && dfs(i))break;
    }

    if(st==-1){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    vector<int>cycle;
    cycle.push_back(st);
    for(int v=ed;v!=st;v=par[v]){
        cycle.push_back(v);
    }
    cycle.push_back(st);
    reverse(cycle.begin(),cycle.end());

    cout<<cycle.size()<<'\n';
    for(auto c:cycle){
        cout<<c+1<<' ';
    }
    cout<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}