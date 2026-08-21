#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int N;
vector<bool>visited;
vector<vector<bool>>g;
void dfs(int u){
    if(visited[u])return;
    visited[u]=true;
    for (int i = 0; i < N; i++)
    {
        if(g[u][i]||g[i][u])dfs(i);
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin>>N;
    vector<ll>x(N),y(N),r(N);
    visited.assign(N,false);
    g.assign(N,vector<bool>(N,false));
    ll sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    for (int i = 0; i < N; i++)
    {
        cin>>x[i]>>y[i]>>r[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(i==j)continue;
            ll d = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            g[i][j]=(d<=(r[i]+r[j])*(r[i]+r[j]) && d>=(r[i]-r[j])*(r[i]-r[j]));
        }
    }
    int S,T;
    for (int i = 0; i < N; i++)
    {
        ll ds = (x[i]-sx)*(x[i]-sx)+(y[i]-sy)*(y[i]-sy);
        ll dt = (x[i]-tx)*(x[i]-tx)+(y[i]-ty)*(y[i]-ty);
        if(ds==r[i]*r[i])S=i;
        if(dt==r[i]*r[i])T=i;
    }
    dfs(S);
    if(visited[T])cout<<"Yes\n";
    else cout<<"No\n";

    return 0;

}