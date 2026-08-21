#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;//998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N,M,S;
    cin>>N>>M>>S;
    S--;
    vector<vector<int>>g(N);
    for (int i = 0; i < M; i++)
    {
        int x,y;
        cin>>x>>y;
        if(x!=y)g[x-1].push_back(y-1);
    }
    vector<int>D(N,-1);
    queue<int>q;
    D[S]=0;
    q.push(S);

    while (!q.empty())
    {
        int cur = q.front();
        for (auto u:g[cur])
        {
            if(D[u]==-1){
                D[u]=D[cur]+1;
                q.push(u);
            }
        }
        q.pop();
    }
    for(auto d:D){
        cout<<d<<" ";
    }

    return 0;

}