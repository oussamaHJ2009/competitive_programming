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

void solve() {
    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];

            vector<vector<ll>>hsum(2,vector<ll>(n)),vsum(2,vector<ll>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            hsum[j%2][i]+=a[i][j];
            vsum[i%2][j]+=a[i][j];
        }
    }
    ll s1=0,s2=0;

    for (int i = 0; i < n; i++)
    {
        s1+=max(hsum[0][i],hsum[1][i]);
        s2+=max(vsum[0][i],vsum[1][i]);
    }
    cout<<max(s1,s2)<<'\n';
}

int main() {
    setIO("");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}