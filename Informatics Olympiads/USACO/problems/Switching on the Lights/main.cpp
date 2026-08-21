#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

int n,m;
bool G[167][167];
map<pair<int,int>,vector<pair<int,int>>>S;
bool lit[167][167];
int dirX[]={1,0,-1,0};
int dirY[]={0,1,0,-1};

void flo(int i,int j){
    if(!lit[i][j]||G[i][j]==1)return;
    G[i][j]=1;

    for (auto [x,y]:S[{i,j}])
    {
        lit[x][y]=true;
        for (int k = 0; k < 4; k++)
        {
            if(x+dirX[k]>0 && x+dirX[k]<=n && y+dirY[k]>0 && y+dirY[k]<=n){
                if(G[x+dirX[k]][y+dirY[k]])flo(x,y);
            }
        }

    }
    for (int k = 0; k < 4; k++)
        {
            if(i+dirX[k]>0 && i+dirX[k]<=n && j+dirY[k]>0 && j+dirY[k]<=n){
                flo(i+dirX[k],j+dirY[k]);
            }
        }
}

void solve() {
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        S[{x,y}].push_back({a,b});
    }
    for (int i = 0; i < 167; i++)
    {
        for (int j = 0; j < 167; j++)
        {
            G[i][j]=false;
            lit[i][j]=false;
        }
    }
    lit[1][1]=true;
    flo(1,1);
    int ans=0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans+=lit[i][j];
        }
        
    }
    cout<<ans<<'\n';
}

int main() {
    setIO("lightson");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}