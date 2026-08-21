#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

struct dsu{
    vector<int>p,sz;
    int N,mxsz=1;
    void build(int n){
        p.resize(n);
        sz.assign(n,1);
        iota(p.begin(),p.end(),0);
        N=n;
    }
    int find(int u){
        while (p[u]!=u)
            u=p[u];
        return u;
    }
    bool unite(int u,int v){
        u=find(u),v=find(v);
        if(u==v)return false;
        N--;
        if(sz[v]>sz[u])swap(u,v);
        sz[u]+=sz[v];
        p[v]=p[u];
        mxsz=max(mxsz,sz[u]);
        return true;
    }
    
};

void solve() {
    int n,m;
    cin>>n>>m;
    dsu g;
    g.build(n);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        g.unite(a,b);
        cout<<g.N<<" "<<g.mxsz<<'\n';
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}