#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int INF = 1e9;

int Dr[4] = {1,-1,0,0};
int Dc[4] = {0,0,1,-1};

void solve() {
    int w,h;
    cin>>h>>w;
    vector<string>s(h,string(w,' '));
    vector<vector<bool>>vis(h,vector<bool>(w,0));
    vector<vector<int>>d(h,vector<int>(w,INF));
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>s[i][j];
    auto in = [&](int r,int c){
        return r<h && r>=0 && c<w && c>=0 && s[r][c]!='.';
    };

    deque<pair<int,int>>q;
    q.push_front({0,0});
    d[0][0]=1;
    vis[0][0]=1;
    int ans=0;
    while(!q.empty()){
        auto [r,c]=q.front();q.pop_front();
        ans=max(ans,d[r][c]);
        for(int i=0;i<4;i++){
            int nr=r+Dr[i],nc=c+Dc[i];
            if(!in(nr,nc) || vis[nr][nc])continue;
            d[nr][nc] = d[r][c] + (s[r][c] != s[nr][nc]);
            if(s[r][c]!=s[nr][nc])q.push_back({nr,nc});
            else q.push_front({nr,nc});
            vis[nr][nc] = 1;
        }
    }
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}