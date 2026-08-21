#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int N = 20;
int dp[1<<N];

int pcnt(int x){
    return __builtin_popcount(x);
}

void solve() {
    int n,L;
    cin>>n>>L;
    vector<int>D(n);
    vector<vector<int>>st(n);
    for(int i=0;i<n;i++){
        int C;
        cin>>D[i]>>C;
        while(C--){
            int x;cin>>x;
            st[i].push_back(x);
        }
    }
    dp[0]=0;
    for(int S=0;S<(1<<n);S++){
        for(int i=0;i<n;i++){
            if((S>>i & 1)==0){
                int pt = upper_bound(st[i].begin(),st[i].end(), dp[S]) - st[i].begin() - 1;
                if(pt>=0)dp[S|(1<<i)] = max(dp[S|(1<<i)], st[i][pt] + D[i]);
            }
        }
    }
    int ans = 25;
    for(int i=0;i<(1<<n);i++){
        if(dp[i]>=L)ans=min(pcnt(i),ans);
    }
    if(ans==25)cout<<-1<<'\n';
    else cout<<ans<<'\n';
}

int main() {
    setIO("movie");
    solve();
    return 0;
}