#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>adj(n);
        for (int i = 0; i < m; i++)
        {
            int v,u;cin>>v>>u;
            adj[v-1].push_back(u-1);
            adj[u-1].push_back(v-1);
        }
        //?????fr idk what to do chat ????????
    }

    return 0;

}