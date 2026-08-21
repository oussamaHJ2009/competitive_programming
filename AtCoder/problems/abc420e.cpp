//problem link: https://atcoder.jp/contests/abc420/tasks/abc420_e
//written by a rando

//look out for typos!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

struct dsu{
    vector<int>p,sz,cnt;
    void init(int n){
        sz.assign(n,1);
        cnt.assign(n,0);
        p.resize(n);
        iota(p.begin(),p.end(),0);
    }

    int find(int u){
        while(p[u]!=u)u=p[u];
        return u;
    }

    void unite(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v)return;
        if(sz[v]>sz[u])swap(v,u);
        sz[u]+=sz[v];
        cnt[u]+=cnt[v];
        p[v]=u;
    }

    void color(int u,int c){
        u=find(u);
        cnt[u]+=c;
    }

    string ans(int u){
        u=find(u);
        if(cnt[u]>0)return "Yes\n";
        else return "No\n";
    }
};

void solve() {
    int n,q;
    cin>>n>>q;
    vector<int>col(n,0);
    dsu g;
    g.init(n);
    while (q--)
    {
        int ty;cin>>ty;
        if(ty==1){
            int a,b;
            cin>>a>>b;
            a--;b--;
            g.unite(a,b);
        }
        if(ty==2){
            int a;cin>>a;a--;
            col[a]=1-col[a];
            g.color(a,col[a]?1:-1);
        }
        if(ty==3){
            int a;cin>>a;a--;
            cout<<g.ans(a);
        }
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

