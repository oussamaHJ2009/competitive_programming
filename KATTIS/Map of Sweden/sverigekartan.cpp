//problem link: https://open.kattis.com/problems/sverigekartan
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int R,C,U;
vector<string>M;
vector<vector<bool>>v;

int X[] = {1,0,-1,0};
int Y[] = {0,1,0,-1};

bool in(int i,int j){
    return (i>=0 && i<R && j>=0 && j<C);
}

int cnt=0;

void flo(int i,int j){
    if(!in(i,j))return;
    if(M[i][j]=='.'||v[i][j])return;
    v[i][j]=1;
    if(M[i][j]!='.')cnt++;
    for(int d=0;d<4;d++){
        flo(i+X[d],j+Y[d]);
    }
}

void solve() {
    cin>>R>>C>>U;
    M.assign(R,string(C,' '));
    v.assign(R,vector<bool>(C));

    pair<int,int>S;
    for(int i=0;i<R;i++)for(int j=0;j<C;j++){
        cin>>M[i][j];
        if(M[i][j]=='S')S={i,j};
    }

    flo(S.first,S.second);
    cout<<cnt<<'\n';
    for (int u = 0; u < U; u++)
    {
        int r,c;
        cin>>r>>c;
        r--;c--;
        M[r][c]='#';
        for (int d = 0; d < 4; d++)
        {
            if(in(r+X[d],c+Y[d]) && v[r+X[d]][c+Y[d]]){
                flo(r,c);
                break;
            }
        }
        cout<<cnt<<'\n';
    }
    
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