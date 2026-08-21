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
    int n;
    cin>>n;
    vector<int>deg(n);
    for (int i = 0; i < n-1; i++)
    {
        int u,v;cin>>u>>v;
        u--;v--;
        deg[u]++;deg[v]++;
    }
    int ans=*max_element(deg.begin(),deg.end()) + 1;
    cout<<ans<<'\n';
}

int main() {
    setIO("planting");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}