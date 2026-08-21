#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const int inf=1e9;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=inf;
    ans=min((s[0]=='R'?a[0]:inf),(s[n-1]=='L'?a[n-1]:inf));
    int mnR=inf,mnL=inf;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='R')mnR=min(mnR,a[i]);
        else ans=min(ans,mnR+a[i]);
    }
    for (int i = n-1; i >= 0; i--)
    {
        if(s[i]=='L')mnL=min(mnL,a[i]);
        else ans=min(ans,mnL+a[i]);
    }
    for (int i = 1; i < n; i++)
    {
        if(s[i]=='R' && s[i-1]=='L')ans=min(ans,a[i]+a[i-1]);
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