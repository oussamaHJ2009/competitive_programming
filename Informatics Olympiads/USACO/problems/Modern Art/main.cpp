#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    
    

    int N;
    cin>>N;
    vector<vector<int>>G(N,vector<int>(N));
    vector<int>top(10,1e9),bot(10,-1),left(10,1e9),right(10,-1);
    vector<bool>ok(10,false);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char curr;
            cin>>curr;
            int cur=curr-'0';
            G[i][j]=cur;
            top[cur]=min(top[cur],i);
            bot[cur]=max(bot[cur],i);
            left[cur]=min(left[cur],j);
            right[cur]=max(right[cur],j);
            ok[cur]=true;
        }
    }

    for (int col = 1; col < 10; col++)
    {
        for (int i = top[col]; i <= bot[col]; i++)
        {
            for (int j = left[col]; j <= right[col]; j++)
            {
                if(G[i][j]!=col)ok[G[i][j]]=false;
            }
        }
    }
    int ans=0;
    for (int i = 1; i < 10; i++)
    {
        ans+=ok[i];
    }
    cout<<ans;

    return 0;

}