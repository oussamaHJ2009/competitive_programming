#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>>x(n);
    vector<int>y(n);
    for (int i = 0; i < n; i++)
    {
        cin>>x[i].first>>y[i];
        x[i].second=i;
    }
    sort(x.begin(),x.end());
    vector<vector<int>>top(n,vector<int>(n+1,0)),bot(n,vector<int>(n+1,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            top[i][j]=top[i][j-1]+(y[x[j-1].second]>y[i]);
            bot[i][j]=bot[i][j-1]+(y[x[j-1].second]<y[i]);
        }
    }

    ll ans=n+1;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            ll a,b,to,bo;
            to=(y[x[i].second]>y[x[j].second]?x[i].second:x[j].second);
            bo=(y[x[i].second]<y[x[j].second]?x[i].second:x[j].second);
            a=top[to][j+1]-top[to][i];
            b=bot[bo][j+1]-bot[bo][i];
            ans+=(a+1)*(b+1);
        }
    }
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