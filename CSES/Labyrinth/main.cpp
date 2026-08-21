#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int Dr[4] = {1,-1,0,0};
int Dc[4] = {0,0,1,-1};

const int INF=1e9;

void solve() {
    int n,m;cin>>n>>m;
    vector<string>g(n,string(m,' '));
    pair<int,int>st,en;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]=='A'){
                st={i,j};
            }else if(g[i][j]=='B'){
                en={i,j};
            }
        }
    }
    auto in = [&](int r,int c){
        return r>=0 && r<n && c>=0 && c<m && g[r][c]!='#';
    };
    vector<vector<int>>d(n,vector<int>(m,INF));
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    vector<vector<pair<int,int>>>p(n,vector<pair<int,int>>(m,{-1,-1}));
    queue<pair<int,int>>q;
    d[st.first][st.second]=0;
    vis[st.first][st.second]=1;
    q.push(st);
    
    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nr = r+Dr[i], nc = c+Dc[i];
            if(in(nr,nc) && !vis[nr][nc]){
                vis[nr][nc]=1;
                q.push({nr,nc});
                p[nr][nc] = {r,c};
                d[nr][nc]=d[r][c]+1;
            }

        }
    }
    if(d[en.first][en.second]==INF){
        cout<<"NO\n";
        return;
    }
    string path="";
    pair<int,int>cur=en;
    while(cur!=st){
        auto [pr,pc] = p[cur.first][cur.second];
        auto [r,c] = cur;
        if(pr-r==1 && pc-c==0)path+='U';
        else if(pr-r==-1 && pc-c==0)path+='D';
        else if(pr-r==0 && pc-c==1)path+='L';
        else if(pr-r==0 && pc-c==-1)path+='R';
        cur=p[r][c];
    }
    reverse(path.begin(),path.end());
    cout<<"YES\n";
    cout<<path.size()<<'\n';
    cout<<path<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}