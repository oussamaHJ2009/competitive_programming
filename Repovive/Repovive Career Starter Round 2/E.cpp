#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int n,m;
vector<vector<int>>S;
vector<tuple<int,int,int>>ans(0);
vector<pair<int,int>>ty{{0,0},{1,0},{1,1},{0,1}};
void sq(int x,int y,vector<vector<int>>&S){
    int p=0;
    while (S[x][y]==1 || S[x+1][y]==1 || S[x][y+1]==1 || S[x+1][y+1]==1)
    {
        ans.push_back({p,x+ty[p].first,y+ty[p].second});
        S[x+ty[p%4].first][y+ty[p%4].second]^=1;
        S[x+ty[(p+1)%4].first][y+ty[(p+1)%4].second]^=1;
        S[x+ty[(p+3)%4].first][y+ty[(p+3)%4].second]^=1;
        p=(p+1)%4;
    }
}

void solve() {
    cin>>n>>m;
    S.assign(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;cin>>c;
            S[i][j]=c-'0';
        }
    }

    for (int i = 0; i < n-1; i+=2)
    {
        for (int j = 0; j < m-1; j+=2)
        {
            sq(i,j,S);
        }
    }
    if(n%2){
        for (int i = 0; i < m-1; i+=2)
        {
            sq(n-2,i,S);
        }
    }
    if(m%2){
        for (int i = 0; i < n-1; i+=2)
        {
            sq(i,m-2,S);
        }
    }
    if(m%2 && m%2){
        sq(n-2,m-2,S);
    }
    cout<<ans.size()<<'\n';
    for (auto [a,b,c]:ans)
    {
        cout<<a+1<<' '<<b+1<<' '<<c+1<<'\n';
    }
    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}