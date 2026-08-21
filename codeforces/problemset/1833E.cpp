//problem link: https://codeforces.com/contest/1833/problem/E
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int n;
vector<set<int>>g;
vector<int>col;
int c;

void dfs(int u){
    if(col[u]!=-1)return;
    col[u]=c;
    for(auto v:g[u]){
        dfs(v);
    }
}

void solve() {
    cin>>n;
    g.assign(n,set<int>());
    col.assign(n,-1);
    c=0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        --a;
        g[i].insert(a);
        g[a].insert(i);
    }
    for(int i=0;i<n;i++){
        if(col[i]==-1){
            dfs(i);
            c++;
        }
    }

    // for(int i=0;i<n;i++){
    //     cerr<<i+1<<"-> ";
    //     for (auto u:g[i])
    //     {
    //         cerr<<u+1<<' ';
    //     }
    //     cerr<<'\n';
    // }

    int join=0;
    for(int i=0;i<n;i++){
        if(g[i].size()==1)join++;
    }
    join>>=1;
    cout<<c-(join>0?join-1:0)<<" "<<c<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        // cerr<<"tc\n";
        solve();
    }
    
    return 0;
}