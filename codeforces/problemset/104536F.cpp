/*
*created: 2026-08-10 at 07:48:34
*problem: F. Minimize the Diameter, link: https://codeforces.com/gym/104536/problem/F
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>>T1,T2;
vector<int>d1,d2;

void dfs(vector<vector<int>>&T,vector<int>&d ,int u,int p,int dpth){
    d[u]=dpth;
    for(auto v:T[u]){
        if(v!=p)dfs(T,d,v,u,dpth+1);
    }
}

void solve() {
    int n,m;
    cin>>n;
    T1.assign(n,vector<int>());
    d1.assign(n,0);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        T1[a].push_back(b);
        T1[b].push_back(a);
    }
    cin>>m;
    T2.assign(m,vector<int>());
    d2.assign(m,0);
    for(int i=0;i<m-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        T2[a].push_back(b);
        T2[b].push_back(a);
    }

    dfs(T1,d1,0,-1,0);
    dfs(T2,d2,0,-1,0);

    int s1 = max_element(d1.begin(),d1.end()) - d1.begin();
    int s2 = max_element(d2.begin(),d2.end()) - d2.begin();

    dfs(T1,d1,s1,-1,0);
    dfs(T2,d2,s2,-1,0);

    int ans = max({*max_element(d1.begin(),d1.end()), *max_element(d2.begin(),d2.end()), (*max_element(d1.begin(),d1.end())+1)/2 + (*max_element(d2.begin(),d2.end())+1)/2 + 1});

    cout<<ans<<'\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}