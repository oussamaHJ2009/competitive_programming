/*
USACO 2020 January Contest, Silver
Problem 3. Wormhole Sort 
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

vector<vector<pair<int,int>>>G;
vector<bool>visited;

void dfs(int u,int lim){
    if(visited[u])return;
    visited[u]=true;
    for (auto v:G[u])
    {
        if(v.second>=lim)dfs(v.first,lim);
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    int N,M;
    cin>>N>>M;
    G.assign(N,vector<pair<int,int>>());
    visited.assign(N,false);
    vector<int>P(N);
    for (int i = 0; i < N; i++)
    {
        cin>>P[i];
        P[i]--;
    }
    vector<int>W(M);
    for (int i = 0; i < M; i++)
    {
        int a,b,w;
        cin>>a>>b>>W[i];
        a--;b--;
        G[a].push_back({b,W[i]});
        G[b].push_back({a,W[i]});
    }
    sort(W.begin(),W.end());
    int lo=0, hi=M-1;
    int S=0;
    while (P[S]==S)S++;
    int ans=-1;
    while (lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        visited.assign(N,false);
        bool ok=false;
        if(S<N){dfs(S,W[mid]);ok=true;}
        for (int i = 0; i < N && ok; i++)
        {
            if(!visited[i] && P[i]!=i)ok=false;
        }
        if(ok){
            ans=W[mid];
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    
    cout<<ans<<endl;

    return 0;

}