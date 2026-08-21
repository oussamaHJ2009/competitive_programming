#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int MAXN = 100005;
vector<int>g[MAXN];
string s;
int id[MAXN];
int cur=0;

void dfs(int u,int prev){
    id[u]=cur;
    for(auto v:g[u]){
        if(v!=prev and s[v]==s[u]){
            dfs(v,u);
        }
    }
}

void solve() {
    int N,M;
    cin>>N>>M;
    cin>>s;
    for (int i = 0; i < N-1; i++)
    {
        int u,v;
        cin>>u>>v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }

    for (int i = 0; i < N; i++)id[i]=-1;
    
    for(int i=0;i<N;i++)if(id[i]==-1){
        dfs(i,-1);
        cur++;
    }

    for (int i = 0; i < M; i++)
    {
        int st,e;
        char p;
        cin>>st>>e>>p;
        st--;e--;
        if(id[st]==id[e] && s[st]!=p)cout<<0;
        else cout<<1;
    }
}

int main() {
    setIO("milkvisits");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}