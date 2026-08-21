#include <bits/stdc++.h>
using namespace std;

using ld = long double;

void solve() {
    int n;
    cin>>n;
    vector<ld>c(n),p(n);
    for (int i = 0; i < n; i++)
    {
        cin>>c[i]>>p[i];
        p[i]/=100.0;
    }
    ld dp=0;
    for (int i = n - 1; i >= 0; i--)
    {
        dp=max(dp,dp*(1-p[i]) + c[i]);
    }
    cout<<fixed<<setprecision(10)<<dp<<'\n';
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