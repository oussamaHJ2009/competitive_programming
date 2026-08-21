#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}
const ll INF = 1e18;

ll dp[1<<20]{0}, ok[1<<20]{0};

void solve() {
    ll N;
    ll H;
    cin>>N>>H;
    vector<ll>h(N),w(N),s(N);
    for(ll i=0;i<N;i++){
        cin>>h[i]>>w[i]>>s[i];
    }
    for(int i = 0; i < (1<<N); i++) {
        dp[i] = -INF;
        ok[i] = 0;
    }
    dp[0] = INF;
    for(int S=1;S<(1<<N);S++){
        ll sum=0;
        for(ll i=0;i<N;i++){
            if((S>>i) & 1){
                dp[S] = max(dp[S], min(dp[S ^ (1<<i)] - w[i], s[i]));
                sum+=h[i];
            }
        }
        ok[S] = (sum>=H && dp[S]>=0);
    }

    ll ans = -1;
    for(ll S=1;S<(1<<N);S++){
        if(ok[S])ans=max(ans,dp[S]);
    }
    if(ans<0){
        cout<<"Mark is too tall\n";
    }else cout<<ans<<'\n';
}

int main() {
    setIO("guard");
    solve();
    return 0;
}