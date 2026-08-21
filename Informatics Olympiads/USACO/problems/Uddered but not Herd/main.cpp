#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 1e9;

vector<vector<int>>g;
vector<int>dp;

void solve() {
    string s;
    cin>>s;
    map<char,int>mp;
    for(char c:s){if(!mp.count(c))mp[c] = (int)mp.size();}
    int n = (int)mp.size();
    g.assign(n,vector<int>(n,0));
    dp.assign(1<<n,INF);
    dp[0]=1;
    for(int i=1;i<s.size();i++){
        g[mp[s[i - 1]]][mp[s[i]]]++;
    }
    
    for(int S=1;S<(1<<n);S++){
        for(int i=0;i<n;i++){
            if(!(S>>i & 1))continue;
            int w=0;
            for(int j=0;j<n;j++){
                if(!(S>>j & 1))continue;
                w += g[i][j];
            }
            dp[S] = min(dp[S], dp[S ^ (1<<i)] + w);
        }
    }

    cout<<dp[(1<<n) - 1]<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}