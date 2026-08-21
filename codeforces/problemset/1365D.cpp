//problem link: https://codeforces.com/contest/1365/problem/D
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int n,m;
vector<string>s;
vector<vector<bool>>v;

int X[] = {1,0,-1,0};
int Y[] = {0,1,0,-1};
bool in(int i,int j){
    return (i<n && i>=0 && j<m && j>=0);
}

int G_cnt;

void flo(int i, int j){
    if(!in(i,j))return;
    if(s[i][j]=='#' || v[i][j])return;
    v[i][j] = 1;
    if(s[i][j]=='G')G_cnt++;
    for (int d = 0; d < 4; d++)
    {
        flo(i+X[d],j+Y[d]);
    }
}

void solve() {
    cin>>n>>m;
    s.assign(n,string(m,' '));
    v.assign(n,vector<bool>(m));
    G_cnt=0;

    int good=0;
    stack<pair<int,int>>bad;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>s[i][j];
            if(s[i][j]=='B'){
                bad.push({i,j});
            }
            if(s[i][j]=='G')good++;
        }
    }

    while (!bad.empty())
    {
        auto [i,j] = bad.top();bad.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            if(in(i+X[dir],j+Y[dir])){
                if(s[i+X[dir]][j+Y[dir]] == 'G'){
                    cout<<"NO\n";
                    return;
                }else if(s[i+X[dir]][j+Y[dir]] == '.')s[i+X[dir]][j+Y[dir]]='#';
            }
        }
    }
    
    flo(n-1,m-1);
    if(G_cnt==good){
        cout<<"YES\n";
    }else cout<<"NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}