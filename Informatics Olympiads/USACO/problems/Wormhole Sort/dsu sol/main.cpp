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
    vector<int>p,sz;
    int N;
    void init(int n){
        N=n;
        p.resize(n);
        for(int i=0;i<n;i++)p[i]=i;
        sz.assign(n,1);
    }
    int find(int u){
        while(u!=p[u])u=p[u];
        return u;
    }
    void unite(int u , int v){
        u=find(u);
        v=find(v);
        if(u==v)return;
        if(sz[v]>sz[u])swap(u,v);
        sz[u]+=sz[v];
        p[v]=u;
    }
    bool connected(int u,int v){
        return find(u)==find(v);
    }
};

struct worm{
    int u,v,w;
    bool operator<(worm y){return w<y.w;}
};

void solve() {
    int n,m;
    cin>>n>>m;
    dsu g;
    vector<int>cow(n);
    for (int i = 0; i < n; i++)
    {
        cin>>cow[i];
        cow[i]--;
    }
    g.init(n);
    vector<worm>e(m);
    for(auto &wo:e){
        cin>>wo.u>>wo.v>>wo.w;
        wo.u--;wo.v--;
    }
    sort(e.begin(),e.end());
    int ans=-1;
    int cur=m;
    for (int i = 0; i < n; i++)
    {
        while (!g.connected(i,cow[i]))
        {
            g.unite(e[cur].u,e[cur].v);
            ans=e[cur].w;
            cur--;
        }
    }
    
    cout<<ans<<'\n';
}

int main() {
    setIO("wormsort");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}