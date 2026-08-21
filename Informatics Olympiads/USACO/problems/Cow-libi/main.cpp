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

struct loc{
    ll x,y,t;
};

bool cmp(loc a, loc b){
    return a.t < b.t;
}

void solve() {
    int G,N;
    cin>>G>>N;
    vector<loc>g(G);
    vector<loc>cow(N);
    for (int i = 0; i < G; i++)
    {
        cin>>g[i].x>>g[i].y>>g[i].t;
    }
    for (int i = 0; i < N; i++)
    {
        cin>>cow[i].x>>cow[i].y>>cow[i].t;
    }
    int ans=0;
    sort(g.begin(),g.end(),cmp);
    for (int i = 0; i < N; i++)
    {
        int sus = upper_bound(g.begin(),g.end(),cow[i],cmp) - g.begin();
        bool ac=0;
        for (int j = sus-1; j <= sus; j++)
        {
            if(j>=0 && j < G){
                ll dur=(cow[i].t - g[j].t)*(cow[i].t - g[j].t);
                ll D = (cow[i].x - g[j].x)*(cow[i].x - g[j].x) + (cow[i].y - g[j].y)*(cow[i].y - g[j].y);
                if(D>dur)ac=1;
            }
        }
        ans+=ac;
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