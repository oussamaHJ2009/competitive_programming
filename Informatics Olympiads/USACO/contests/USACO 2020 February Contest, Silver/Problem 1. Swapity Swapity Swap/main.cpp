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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>suc(n);
    iota(suc.begin(),suc.end(),0);
    for (int i = 0; i < m; i++)
    {
        int l,r;cin>>l>>r;
        reverse(suc.begin()+l-1,suc.begin()+r);
    }

    vector<pair<int,int>>v(n,{-1,-1});
    vector<vector<int>>cc;
    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        if(v[i].first==-1){
            vector<int>c;
            int u=i;
            while (v[u].first==-1)
            {
                v[u]={cnt,c.size()};
                c.push_back(u);
                u=suc[u];
            }
            cc.push_back(c);
            cnt++;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        int ans = cc[v[i].first][(v[i].second+k)%(int)cc[v[i].first].size()] + 1;
        cout<<ans<<'\n';
    }
    
}

int main() {
    setIO("swap");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

