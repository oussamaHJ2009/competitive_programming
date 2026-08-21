#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int X[] = {1,0,-1,0};
int Y[] = {0,1,0,-1};

vector<vector<bool>>v;
int n,m;

void flo(int i,int j){
    if(i<0 || i>=n || j>=m || j<0)return;
    if(v[i][j] == 1)return;
    v[i][j] = 1;
    for (int d = 0; d < 4; d++)
        flo(i+X[d],j+Y[d]);
}

void solve() {
    cin>>n>>m;
    v.assign(n,vector<bool>(m,false));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){char c;cin>>c;v[i][j]=(c=='#');}
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!v[i][j]){
                flo(i,j);
                ans++;
            }
        }
    }
    
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}