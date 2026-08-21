// problem link: https://codeforces.com/contest/468/problem/B
// written by a rando

#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

using ll = int64_t;

struct dsu{
    vector<int>e;
    dsu(int n){
        e.assign(n+2,-1);
    }
    int find(int u){
        return(e[u]<0?u:e[u]=find(e[u]));
    }
    void unite(int u, int v){
        u=find(u),v=find(v);
        if(u==v)return;
        if(e[u]>e[v])swap(u,v);
        e[u]+=e[v];
        e[v]=u;
    }
    bool taken(int u){
        return e[find(u)]<-1;
    }
};

void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    int A=n,B=n+1;
    dsu g(n);
    vector<int>p(n);
    map<int,int>id;
    for (int i = 0; i < n; i++)
    {
        cin>>p[i];
        id[p[i]]=i;
    }
    for (int i = 0; i < n; i++)
    {
        if(id.count(a-p[i])){
            g.unite(id[a-p[i]],i);
        }else{
            g.unite(B,i);
        }
        if(id.count(b-p[i])){
            g.unite(id[b-p[i]],i);
        }else{
            g.unite(A,i);
        }
    }
    
    if(g.find(A)==g.find(B)){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for (int i = 0; i < n; i++)
    {
        if(g.find(i) == g.find(A)){
            cout<<"0 ";
        }else {
            cout<<"1 ";
        }
    }
    

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}