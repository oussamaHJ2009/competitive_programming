#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = INT64_MIN;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve() {
    ll N,W;
    cin>>N>>W;
    vector<ll>w(N),t(N);
    ll S = 0;
    for (ll i = 0; i < N; i++)
    {
        cin>>w[i]>>t[i];
        S=max(w[i],S);
    }
    S+=W;
    vector<ll>dp(S+1,INF);
    dp[0]=0;
    for (ll i = 0; i < N; i++)
    {
        for (ll s = S; s >= w[i]; s--)
        {
            dp[s] = max(dp[s],dp[s-w[i]] + t[i]);
        }
    }
    ll ans = 0;
    for (ll i = W; i <= S; i++)
    {
        if(dp[i]>=0)ans = max((dp[i]*1000LL)/i ,ans);
    }
    
    cout<<ans<<'\n';
}

int main() {
    setIO("talent");
    ll run_case = 1;
    while (run_case--) {
        solve();
    }
    return 0;
}