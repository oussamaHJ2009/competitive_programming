#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

void dfs(int u,vector<vector<int>> &G,vector<bool> &visited){
    for (int v:G[u])
    {
        if(visited[v])continue;
        visited[v]=true;
        dfs(v,G,visited);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>GF(n);
    vector<vector<int>>GR(n);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        GF[a].push_back(b);
        GR[b].push_back(a);
    }

    vector<bool>visited;
    visited.assign(n,false);
    dfs(0,GF,visited);
    for (int i = 1; i < n; i++)
    {
        if(!visited[i]){
            cout<<"NO\n"<<1<<" "<<i+1;
            return 0;
        }
    }

    visited.assign(n,false);
    dfs(0,GR,visited);
    for (int i = 1; i < n; i++)
    {
        if(!visited[i]){
            cout<<"NO\n"<<i+1<<" "<<1;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;

}