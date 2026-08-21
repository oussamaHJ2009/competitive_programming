#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin>>n>>m;
    vector<vector<bool>>cnt(n+1,vector<bool>(n+1,false));
    bool ok =true;
    for (int i = 0; i < m; i++)
    {
        int k;cin>>k;
        vector<int>p(k);
        for (int j = 0; j < k; j++)
        {
            cin>>p[j];
        }
        for (int j = 0; j < k; j++)
        {
            for (int f = 0; f < k; f++)
            {
                cnt[p[f]][p[j]]=true;
                cnt[p[j]][p[f]]=true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cnt[i][i]=true;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(cnt[i][j]==false){
                ok=false;
                break;
            }
        }
    }
    if(ok)cout<<"Yes";
    else cout<<"No";

    return 0;

}