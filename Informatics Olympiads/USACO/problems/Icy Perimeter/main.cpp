#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

int N;
vector<string>ice;
vector<vector<bool>>v;

int x[] = {1,0,-1,0};
int y[] = {0,1,0,-1};

bool in(int i,int j){
    return (i<N && j<N && i>=0 && j>=0);
}

int cont(int i, int j){
    int ret=4;
    for (int dir = 0; dir < 4; dir++)
    {
        if(in(i+x[dir],j+y[dir]) && ice[i+x[dir]][j+y[dir]]=='#')ret--;
    }
    return ret;
}

int cur_area=0,cur_p=0;

void flo(int i,int j){
    if(!in(i,j))return;
    if(v[i][j] || ice[i][j]=='.')return;
    v[i][j]=1;
    cur_area++;
    cur_p+=cont(i,j);
    for (int dir = 0; dir < 4; dir++)
    {
        flo(i+x[dir],j+y[dir]);
    }
}

void solve() {
    cin>>N;
    ice.assign(N,string(N,' '));
    v.assign(N,vector<bool>(N,false));
    int ans_area=0,ans_p=0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>ice[i][j];
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(!v[i][j]){
                cur_area=0;
                cur_p=0;
                flo(i,j);
                if(cur_area==ans_area){
                    ans_p=min(ans_p,cur_p);
                }else{
                    if(cur_area>ans_area){
                        ans_area=cur_area;
                        ans_p=cur_p;
                    }
                }
            }
        }
    }
    
    cout<<ans_area<<" "<<ans_p;
}


int main() {
    setIO("perimeter");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}