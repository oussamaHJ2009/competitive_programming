#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<bool>cnt(n+1,false);
    for (int i = 0; i < n-1; i++)
    {
        int a;cin>>a;
        cnt[a]=true;
    }
    int ans=1;
    while (cnt[ans])ans++;
    cout<<ans<<'\n';
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