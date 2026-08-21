#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int H,W,K;
    cin>>H>>W>>K;
    vector<vector<int>>G(H+1,vector<int>(W+1));
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            char c;
            cin>>c;
            G[i][j]=c-'0';
        }
    }
    vector<vector<int>>pre(H+1,vector<int>(W+1,0));
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+G[i][j];
        }
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