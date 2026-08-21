#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll MOD1 = 1e9 + 7;
ll MOD2 = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<int> c(m+1),b(n),a(n);
    
    for (int i = 1; i <= m; i++)
    {
        cin>>c[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>a[i]>>b[i];
    }
    int ans= 0;
    for (int i = 0; i < n; i++)
    {
        ans+=min(c[a[i]],b[i]);
        c[a[i]]=max(0,c[a[i]]-b[i]);
        
    }
    
    cout<<ans;
    return 0;

}