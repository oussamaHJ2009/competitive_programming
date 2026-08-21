#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>cnt(n+1,0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        cnt[x]++;
    }
    vector<int>pref(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        pref[i]=cnt[i]+pref[i-1];
    }
    int ans=1;
    for (int g = 1; g <= n; g++)
    {
        int bad=pref[min(n,4*g - 1)];
        if(2*g<=n)bad-=cnt[2*g];
        if(3*g<=n)bad-=cnt[3*g];
        bad-=cnt[g];
        if(bad<=k)ans=g;
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