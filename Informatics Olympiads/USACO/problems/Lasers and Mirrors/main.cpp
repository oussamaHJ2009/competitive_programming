#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

struct pt{
    int x,y;
};

const int INF = 1e9;

void solve() {
    int n;cin>>n;
    vector<pt>a(n+2);
    cin>>a[0].x>>a[0].y>>a[n+1].x>>a[n+1].y;
    map<int,vector<int>>xm,ym;
    for(auto i:{0,n+1}){
        xm[a[i].x].push_back(i);
        ym[a[i].y].push_back(i);
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        xm[a[i].x].push_back(i);
        ym[a[i].y].push_back(i);
    }

    queue<int>q;
    vector<int>d(n+2,INF);
    d[0]=0;
    q.push(0);
    while(!q.empty()){
        int u = q.front();q.pop();
        for(auto v:xm[a[u].x]){
            if(d[v]==INF){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
        for(auto v:ym[a[u].y]){
            if(d[v]==INF){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
        xm[a[u].x].clear();
        ym[a[u].y].clear();
    }
    cout<<(d[n+1]==INF ? -1 : d[n+1]-1)<<'\n';
}

int main() {
    setIO("lasers");
    solve();
    return 0;
}