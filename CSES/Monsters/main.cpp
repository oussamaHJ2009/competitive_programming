#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 1e9;

int Dr[4] = {1,-1,0,0};
int Dc[4] = {0,0,1,-1};
char D[4] = {'D','U','R','L'};

void solve() {
    int n,m;
    cin>>n>>m;
    vector<string>g(n,string(m,' '));
    queue<pair<int,int>>q;
    vector<vector<int>>Md(n,vector<int>(m,INF)),Ad(n,vector<int>(m,INF));
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    pair<int,int>A;
    vector<pair<int,int>>bnd;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]=='M'){
                q.push({i,j});
                Md[i][j]=0;
                vis[i][j]=1;
            }else if (g[i][j]=='A')A={i,j};
            if((i==0 || i==n-1 || j==0 || j==m-1) && g[i][j]!='#')bnd.push_back({i,j});
        }
    }

    auto in=[&](int r,int c){
        return r<n && c<m && r>=0 && c>=0 && g[r][c]!='#';
    };

    vector<string>dir(n,string(m,' '));

    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nr = r + Dr[i];
            int nc = c + Dc[i];
            if(!in(nr,nc) || vis[nr][nc])continue;
            Md[nr][nc] = Md[r][c] + 1;
            q.push({nr,nc});
            vis[nr][nc]=1;
        }
    }
    
    q.push(A);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)vis[i][j]=0;
    vis[A.first][A.second]=1;
    Ad[A.first][A.second]=0;
    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nr = r + Dr[i];
            int nc = c + Dc[i];
            if(!in(nr,nc) || vis[nr][nc])continue;
            Ad[nr][nc] = Ad[r][c] + 1;
            q.push({nr,nc});
            vis[nr][nc]=1;
            dir[nr][nc]=D[i];
        }
    }
    string ans="";
    bool fnd=0;
    for(auto [r,c]:bnd){
        // cerr<<r<<' '<<c<<' '<<Ad[r][c]<<' '<<Md[r][c]<<'\n';        
        if(Ad[r][c] < Md[r][c]){
            while(dir[r][c]!=' '){
                ans+=dir[r][c];
                // cerr<<r<<' '<<c<<'\n';
                if(dir[r][c]=='U')r++;
                else if(dir[r][c]=='D')r--;
                else if(dir[r][c]=='R')c--;
                else if(dir[r][c]=='L')c++;
            }
            reverse(ans.begin(),ans.end());
            fnd=1;
            break;
        }
    }

    if(fnd){
        cout<<"YES\n"<<ans.size()<<'\n'<<ans<<'\n';
    }else{
        cout<<"NO\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}