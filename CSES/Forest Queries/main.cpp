#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,q;
    cin>>n>>q;
    vector<vector<int>>p(n+1,vector<int>(n+1,0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char c;cin>>c;
            p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+(c=='*');
        }
    }
    
    while (q--)
    {
        int i1,i2,j1,j2;
        cin>>i1>>j1>>i2>>j2;
        cout<<p[i2][j2]-p[i1-1][j2]-p[i2][j1-1]+p[i1-1][j1-1]<<'\n';
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