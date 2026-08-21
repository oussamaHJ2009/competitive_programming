#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int N;
vector<pair<int,int>>p;
vector<vector<int>>A;
vector<bool>used;

int cnt(){
    if(p.size()==N){
        int res=0;
        for (int i = 0; i < N; i++)
        {
            res^=A[p[i].first][p[i].second];
        }
        return res;
    }
    int l=0;
    for (int i = 1; i <= 2*N; i++)
    {
        if(!used[i]){l=i;break;}
    }
    used[l]=true;
    int res=0;
    for (int i = 1; i <= 2*N; i++)
    {
        if(!used[i]){
            used[i]=true;
            p.push_back({l,i});
            res=max(res,cnt());
            p.pop_back();
            used[i]=false;
        }
    }
    used[l]=false;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>N;
    used.assign(2*N+1,false);
    A.assign(2*N+1,vector<int>(2*N+1));
    for (int i = 1; i <= 2*N; i++)
    {
        for (int j = i+1; j <= 2*N; j++)
        {
            cin>>A[i][j];
        }
        
    }
    cout<<cnt()<<endl;

    return 0;

}