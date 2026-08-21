#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int N,K,L;
vector<vector<int>>rails;
vector<vector<int>>roads;
vector<int>col_rails;
vector<int>col_roads;
vector<int>ans;

void dfs(vector<vector<int>> &G,int u,int &cur, vector<int> &C){
    if(C[u]!=-1)return;
    C[u]=cur;
    for(auto v:G[u]){
        dfs(G,v,cur,C);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin>>N>>K>>L;
    roads.assign(N,vector<int>());
    rails.assign(N,vector<int>());
    ans.assign(N,1);
    col_rails.assign(N,-1);
    col_roads.assign(N,-1);
    int cur_col_roads = 0;
    int cur_col_rails = 0;

    for (int i = 0; i < K; i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        roads[b].push_back(a);
        roads[a].push_back(b);
    }
    for (int i = 0; i < L; i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        rails[b].push_back(a);
        rails[a].push_back(b);
    }

    for (int i = 0; i < N; i++)
    {
        if(col_rails[i]==-1){
            dfs(rails,i,cur_col_rails,col_rails);
            cur_col_rails++;
        }
        if(col_roads[i]==-1){
            dfs(roads,i,cur_col_roads,col_roads);
            cur_col_roads++;
        }
    }
    
    map<pair<int,int>,int>cnt;
    for (int i = 0; i < N; i++)
    {
        cnt[{col_rails[i],col_roads[i]}]++;
    }
    
    for (int i = 0; i < N; i++)
    {
        cout<<cnt[{col_rails[i],col_roads[i]}]<<" ";
    }
    

    return 0;

}