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
        sz.assign(n,1);
        for(int i=0;i<n;i++)p[i]=i;
    }

    int find(int u){
        while(u!=p[u])u=p[u];
        return u;
    }

    void unite(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v)return;
        if(sz[v]>sz[u])swap(u,v);
        sz[u]+=sz[v];
        p[v]=p[u];
    }
};

struct rel{
    int a, b, r;
    bool operator<(rel x){return r>x.r;}
};

struct qry{
    int k,v,id;
    bool operator<(qry x){return k>x.k;}
};

void solve() {
    int n,q;
    cin>>n>>q;
    vector<rel>e(n-1);
    vector<int>ans(q);
    vector<qry>Q(q);
    dsu g;
    g.init(n);
    for (int i = 0; i < n-1; i++)
    {
        cin>>e[i].a>>e[i].b>>e[i].r;
        e[i].b--;e[i].a--;
    }
    for (int i = 0; i < q; i++)
    {
        cin>>Q[i].k>>Q[i].v;
        Q[i].v--;
        Q[i].id=i;
    }
    sort(e.begin(),e.end());
    sort(Q.begin(),Q.end());

    int cur=0;
    for (auto qq:Q)
    {
        while(cur<n-1 && e[cur].r>=qq.k){
            g.unite(e[cur].a,e[cur].b);
            cur++;
        }
        ans[qq.id]=g.sz[g.find(qq.v)] - 1;
    }
    
    for (auto res:ans)
    {
        cout<<res<<'\n';
    }
    
}

int main() {
    setIO("mootube");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}