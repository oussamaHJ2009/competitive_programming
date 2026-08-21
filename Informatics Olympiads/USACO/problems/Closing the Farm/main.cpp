/*
USACO 2016 US Open Contest, Silver
Problem 3. Closing the Farm
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int N,M;
vector<vector<int>>g;
vector<bool>visited;
vector<bool>closed;
void dfs(int u){
    if(visited[u])return;
    visited[u]=true;
    for (auto v:g[u])
    {
        if(!closed[v])dfs(v);
    }
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    cin>>N>>M;
    visited.assign(N,false);
    g.assign(N,vector<int>(0));
    closed.assign(N,false);
    for (int i = 0; i < M; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    
    int S=0;
    dfs(0);
    bool y=true;
    for (int i = 0; i < N; i++)
    {
        if(!visited[i])y=false;
    }
    if(y)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    for (int i = 0; i < N-1; i++)
    {
        visited.assign(N,false);
        int q;
        cin>>q;
        closed[q-1]=true;
        while(closed[S])S++;
        if(S<N)dfs(S);
        y=true;
        for (int i = 0; i < N; i++)
        {
            if(!visited[i] && !closed[i])y=false;
        }
        if(y)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;

}