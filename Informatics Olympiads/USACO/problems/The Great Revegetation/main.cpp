#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve() {
    int N,M;
    cin>>N>>M;
    vector<vector<pair<int,int>>>adj(N);
    for (int i = 0; i < M; i++)
    {
        char c;
        int u,v;
        cin>>c>>u>>v;
        adj[--u].push_back({c=='D',--v});
        adj[v].push_back({c=='D',u});
    }
    
    vector<int>col(N,-1);
    queue<int>q;
    int ans=0;
    for (int st = 0; st < N; st++)
    {
        if(col[st]==-1){
            bool bip=1;
            q.push(st);
            col[st]=0;
            while (!q.empty())
            {
                int cur = q.front();q.pop();
                for(auto [fac,u]:adj[cur]){
                    if(col[u]!=-1 && col[u]!=col[cur]^fac){
                        bip=0;
                        while(!q.empty())q.pop();
                        break;
                    }else if(col[u]==-1){
                        q.push(u);
                        col[u]=col[cur]^fac;
                    }
                }
            }
            if(!bip){
                ans=0;
                break;
            }
            ans++;
        }
    }
    string s="";
    if(ans==0){
        s+='0';
    }else{
        s+='1';
        for (int i = 0; i < ans; i++)
        {
            s+='0';
        }
    }
    cout<<s<<'\n';
}

int main() {
    setIO("revegetate");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}