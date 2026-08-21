#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

//lens
int M,N;
// vecs to assign
vector<vector<int>>h;
vector<vector<int>>w,v;
//dir
int x[] = {1,0,-1,0};
int y[] ={0,1,0,-1};
//in check
bool in(int i,int j){
    return (i>=0 && i<M && j>=0 && j<N);
}

//flood fill func
void vlo(int i,int j,int D){
    if(!in(i,j))return;
    if(v[i][j])return;
    v[i][j]=1;
    for (int dir = 0; dir < 4; dir++)
    {
        int nxi=i+x[dir],nxj=j+y[dir];
        if(in(nxi,nxj)){
            if(abs(h[i][j]-h[nxi][nxj]) <= D)vlo(nxi,nxj,D);
        }
    }
}

int wi,wj;

bool reach(int D){
    v.assign(M,vector<int>(N,0));
    vlo(wi,wj,D);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(w[i][j] && !v[i][j])return false;
        }
    }
    return true;
}

void solve() {
    cin>>M>>N;
    h.assign(M,vector<int>(N,0));
    w.assign(M,vector<int>(N,0));

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin>>h[i][j];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++){
            cin>>w[i][j];
            if(w[i][j])wi=i,wj=j;
        }

    int lo=0,hi=INT32_MAX;
        int ans=0;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(reach(mid)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    
    cout<<ans<<'\n';
}

int main() {
    setIO("ccski");
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}