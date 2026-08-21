#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int MAXN = 100005;
vector<int>g[MAXN];
long long d[MAXN];

int dfs(int cur,int prev){
    int cows = g[cur].size()+(prev==-1);
    int days=0;
    int cnt=1;
    while (cnt<cows)
    {
        cnt*=2;
        days++;
    }
    for(auto nxt:g[cur]){
        if(nxt!=prev){
            days+=dfs(nxt,cur) + 1;
        }
    }
    return days;
}

void solve() {
    int N;
    cin>>N;
    for(int i=0;i<N-1;i++){
        int cur,v;
        cin>>cur>>v;
        g[--cur].push_back(--v);
        g[v].push_back(cur);
    }
    
    int ans = dfs(0,-1);

    cout<<ans<<'\n';
}

int main() {
    setIO("");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}