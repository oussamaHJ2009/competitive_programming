//problem link: https://atcoder.jp/contests/abc460/tasks/abc460_d
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
int inf = 1e9;
int X[]={1,0,-1,0,1,-1,1,-1};
int Y[]={0,1,0,-1,1,1,-1,-1};

void solve() {
    int h,w;
    cin>>h>>w;

    auto in =[&](int i,int j){return (i<h && 0<=i && j<w && 0<=j);};
    vector<string>a(h);
    for(int i=0;i<h;i++)cin>>a[i];

    vector<string>b(h,string(w,'.'));
    for (int i = 0; i < h; i++)
    {
        for(int j=0;j<w;j++){
            if(a[i][j]=='#'){
                for (int k = 0; k < 8; k++)
                {
                    int x=i+X[k], y=j+Y[k];
                    if(in(x,y) && a[x][y]=='.'){
                        b[x][y]='#';
                    }
                }
            }
        }
    }
    a=move(b);

    queue<pair<int,int>>q;
    vector<vector<int>>D(h,vector<int>(w,inf));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]=='#'){
                D[i][j]=0;
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        auto [i,j]=q.front();q.pop();
        for(int p=0;p<8;p++){
            int x=i+X[p],y=j+Y[p];
            if(in(x,y) && D[x][y]==inf){
                D[x][y]=D[i][j]+1;
                q.push({x,y});
            }
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<((D[i][j]&1)?'#':'.');
        }
        cout<<'\n';
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