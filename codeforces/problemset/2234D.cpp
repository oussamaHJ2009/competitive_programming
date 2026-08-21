#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,k;
    cin>>n>>k;
    string s,z;
    cin>>s>>z;
    ll lz=0,l1=0,rz=0,r1=0,mz=0,m1=0;
    for (int i = 0; i < n; i++)
    {
        lz+=(s[i]-'0')^1;
        l1+=(s[i]-'0');
        rz+=(z[i]-'0')^1;
        r1+=(z[i]-'0');
        m1+=(z[i]-'0')^(s[i]-'0');
        mz+=(z[i]-'0')^(s[i]-'0')^1;
    }
    ll sz=(1<<k)+1;
    ll ans = lz*l1*((sz+2)/3) + rz*r1*((sz+2)/3) + mz*m1*(sz/3);
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