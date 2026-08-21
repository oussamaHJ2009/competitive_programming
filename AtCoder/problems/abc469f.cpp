/*
*created: 2026-08-02 at 17:47:24
*problem: GCD Maximum Spanning Tree, link: https://atcoder.jp/contests/abc469/tasks/abc469_f
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU{
    vector<int>e;
    DSU(int n) : e(n,-1) {}
    int f(int u){
        return e[u]<0?u:e[u]=f(e[u]);
    }
    bool uni(int u,int v){
        u=f(u);
        v=f(v);
        if(u==v)return false;
        if(e[u]>e[v])swap(u,v);
        e[u]+=e[v];
        e[v]=u;
        return true;
    }
};

int id[1000001];

void solve() {
    int n;
    cin>>n;
    DSU dsu(n);
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        id[a[i]]=i;
    }
    ll ans=0,c=0;
    int mx = *max_element(a.begin(),a.end());
    int g = mx;
    while(c<n-1 && g>0){
        int u=-1,v=-1;
        for(int x=g;x<=mx;x+=g){
            if(u==-1)u=id[x];
            else v=id[x];
            if(u!=-1 && v!=-1){
                if(dsu.uni(u,v)){
                    ans+=g;
                    c++;
                }
            }
        }
        g--;
    }
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<1000001;i++)id[i]=-1;
    solve();
    return 0;
}