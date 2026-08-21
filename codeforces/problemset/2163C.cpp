#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>>a(2,vector<int>(n));
    for (int i = 0; i < 2; i++)
    {
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<int>>mn=a,mx=a;
    for (int i = 1; i < n; i++)
    {
        mn[0][i]=min(mn[0][i-1],mn[0][i]);
        mx[0][i]=max(mx[0][i-1],mx[0][i]);
    }
    for (int i = n-2; i >= 0; i--)
    {
        mn[1][i]=min(mn[1][i+1],mn[1][i]);
        mx[1][i]=max(mx[1][i+1],mx[1][i]);
    }
    vector<int>max_l(2*n+2,0);
    for (int i = 0; i < n; i++)
    {
        int cur_l = min(mn[0][i],mn[1][i]);
        int cur_r = max(mx[0][i],mx[1][i]);
        max_l[cur_r]=max(max_l[cur_r],cur_l);
    }
    for (int r = 1; r <= 2*n; r++)
    {
        max_l[r]=max(max_l[r],max_l[r-1]);
    }
    ll ans=0;
    for(int r=1;r<=2*n;r++){
        ans+=max_l[r];
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}