#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int n,m;
vector<vector<int>> graph;
vector<int>color;
vector<bool>visited;
bool ans=true;
void dfs(int at,int c){
    if(visited[at]){
        if(color[at]!=c)ans=false;
        return;
    }
    visited[at]=true;
    color[at]=c;
    for (auto u:graph[at])
    {
        if(c==1)dfs(u,2);
        else dfs(u,1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin>>n>>m;
    color.assign(n,0);
    visited.assign(n,false);
    graph.assign(n,vector<int>(0));
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    
    for (int i = 0; i < n; i++)
    {
        if(!visited[i])dfs(i,1);
    }
    if(ans){
        for (int i = 0; i < n; i++)
        {
            cout<<color[i]<<" ";
        }
    }else{
        cout<<"IMPOSSIBLE";
    }



}