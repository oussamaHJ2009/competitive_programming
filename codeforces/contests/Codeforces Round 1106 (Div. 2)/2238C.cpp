//problem link: https://codeforces.com/contest/2238/problem/C
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int n;
vector<int>d;
vector<vector<int>>adj;
void dfs(int cur, int prev){
    for(auto nxt:adj[cur]){
        if(nxt!=prev){
            
        }
    }
}

void solve() {
    cin>>n;
    d.assign(n,0);
    adj.assign(n,{});
    for (int i = 1; i < n; i++)
    {
        int p;cin>>p;
        adj[p-1].push_back(i);
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}