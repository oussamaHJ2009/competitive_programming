#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n,m;
vector<ll>e,d,p,s,c;
vector<vector<int>>T;
vector<int>diff;
vector<ll>fun;
vector<ll>ans;

void dfs(int u){

    if(u!=1){
        fun[u] = fun[p[u]] + e[u];
        diff[u].assign(diff[p[v]].begin(),diff[p[v]].end());
        diff[u].push_back(d[u]);
    }

    for(auto v:T[u]){
        if(v==p[u])continue;
        dfs(v);
    }
}

void solve() {
    cin>>n>>m;
    e.assign(n,0);
    d.assign(n,0);
    p.assign(n,-1);
    c.assign(m,0);
    s.assign(m,0);
    fun.assign(n,0);
    diff.assign(n,vector<int>());
    ans.assgin(m,0);
    T.assign(n,vector<int>());
    for(int i=1;i<n;i++){
        cin>>p[i]>>d[i]>>e[i];
        p[i]--;
        T[p[i]].push_back(i);
    }
    vector<vector<int>>pc(11);
    for(int i=0;i<m;i++){
        cin>>s[i]>>c[i];
        pc[c[i]].push_back(s[i]);
    }
    for(int i=0;i<11;i++){
        sort(pc[i].begin(),pc[i].end());
    }

    dfs(0);
    
    for(int i=1;i<n;i++)sort(diff[i].begin(),diff[i].end());

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}