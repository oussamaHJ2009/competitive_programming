#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

struct dsu{
    vector<int>p;
    vector<int64_t>sz;
    dsu(int n):p(n,-1),sz(n,1){};
    int find(int u){
        return(p[u]<0?u:p[u]=find(p[u]));
    }
    bool unite(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v)return false;
        if(sz[u]<sz[v])swap(u,v);
        sz[u]+=sz[v];
        p[v]=u;
        return true;
    }
};

int64_t C2(int n){
    return (n*(n-1))/2;
}

void solve() {
    int n,m;
    string s;
    cin>>n>>m>>s;
    dsu g(n);vector<vector<int>>adj(n);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        if(s[i]=='1'){
            g.sz[i]=0;
            for(auto j:adj[i]){
                if(s[j]=='1')g.unite(i,j);
            }
        }
    }
    
    vector<int64_t>ans;
    int64_t cnt=0;
    for(int u=n-1;u>=0;u--){
        if(s[u]=='1'){
            cnt+=g.sz[g.find(u)];
            g.sz[g.find(u)]++;
        }else{
            for (auto v:adj[u])
            {
                if(g.find(u)!=g.find(v) && (v>u||s[v]=='1')){
                    cnt += (g.sz[g.find(u)])*(g.sz[g.find(v)]);
                    g.unite(u,v);
                }
            }
        }
        ans.push_back(cnt);
    }
    reverse(ans.begin(),ans.end());
    for(auto a:ans){
        cout<<a<<'\n';
    }
}

int main() {
    setIO("");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}