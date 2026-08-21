#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int N,M;
vector<vector<int>>g;
vector<pair<int,int>>cords;
vector<int>col;
int cur_col=0;
void dfs(int u){
    if(col[u]!=-1){
        return;
    }
    col[u]=cur_col;
    for (auto v:g[u])
    {
        dfs(v);
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    
    cin>>N>>M;
    g.assign(N,vector<int>());
    cords.assign(N,pair<int,int>());
    col.assign(N,-1);
    for (int i = 0; i < N; i++)
    {
        cin>>cords[i].first>>cords[i].second;
    }
    for (int i = 0; i < M; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    
    for (int i = 0; i < N; i++)
    {
        if(col[i]==-1){
            dfs(i);
            cur_col++;
        }
    }

    vector<pair<int,int>>bot(cur_col,{1e8+1,1e8+1}),top(cur_col,{-1,-1});
    for (int i = 0; i < N; i++)
    {
        top[col[i]].first=max(top[col[i]].first,cords[i].first);
        top[col[i]].second=max(top[col[i]].second,cords[i].second);
        bot[col[i]].first=min(bot[col[i]].first,cords[i].first);
        bot[col[i]].second=min(bot[col[i]].second,cords[i].second);
    }
    
    int ans=1e9;
    for (int i = 0; i < cur_col; i++)
    {
        ans=min(ans,2*(top[i].first - bot[i].first + top[i].second - bot[i].second));
    }
    cout<<ans<<endl;

    return 0;

}