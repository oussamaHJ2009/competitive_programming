#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int N;
vector<vector<int>>g;
vector<bool>visited;
int dfs(int u){
    if(visited[u]){
        return 0;
    }
    visited[u]=true;
    int ret=0;
    for (auto v:g[u])
    {
        ret+=dfs(v);
    }
    return ret+1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    
    cin>>N;
    vector<pair<int,int>>cords(N);
    vector<ll>P(N);
    g.assign(N,vector<int>(0));
    visited.assign(N,false);
    //create the graph'''''
    for (int i = 0; i < N; i++)
    {
        cin>>cords[i].first>>cords[i].second>>P[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            ll D = (cords[i].first-cords[j].first)*(cords[i].first-cords[j].first) + (cords[i].second-cords[j].second)*(cords[i].second-cords[j].second);
            if(P[i]*P[i]>=D)g[i].push_back(j);
            if(P[j]*P[j]>=D)g[j].push_back(i);
        }
    }
    //dfs calls
    int ans=0;
    for (int i = 0; i < N; i++)
    {
        ans=max(ans,dfs(i));
        for (int i = 0; i < N; i++)
        {
            visited[i]=false;
        }
        
    }
    cout<<ans<<endl;

    return 0;

}