#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5+5;

vector<int>adj[N];
vector<int>d;

void dfs(int u,int p,vector<int> &d){
    if(p==-1)d[u]=0;
    else d[u]=d[p]+1;
    for(auto v:adj[u]){
        if(v!=p)dfs(v,u,d);
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int>da(n,0),db(n,0);
    dfs(0,-1,da);
    int a = max_element(da.begin(),da.end()) - da.begin();
    dfs(a,-1,da);
    int b = max_element(da.begin(),da.end()) - da.begin();
    dfs(b,-1,db);

    for(int i=0;i<n;i++){
        cout<<max(da[i],db[i])<<" ";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}