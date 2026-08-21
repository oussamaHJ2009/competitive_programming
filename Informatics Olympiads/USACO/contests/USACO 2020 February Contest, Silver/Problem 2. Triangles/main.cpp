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
const int MX=1e5;
const ll mod = 1e9+7;
const ll comp = 1e4;
vector<ll>gx[MX],gy[MX];
void solve() {
    for (int i = 0; i < MX; i++)
    {
        gx[i].clear();
        gy[i].clear();
    }
    int n;
    cin>>n;
    vector<pair<int,int>>pts(n);
    for (auto &[x,y] : pts)
    {
        cin>>x>>y;
        gx[x+comp].push_back(y);
        gy[y+comp].push_back(x);
    }

    ll ans=0;
    for (auto [x,y]:pts)
    {
        ll sx=0,sy=0;
        for (auto a:gx[x+comp])
        {
            sy+=abs(y-a);
        }
        for (auto b:gy[y+comp])
        {
            sx+=abs(x-b);
        }
        ans = (ans + (sx*sy)%mod)%mod;
    }
    cout<<ans<<'\n';
    
}

int main() {
    setIO("triangles");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}