//problem link: https://codeforces.com/contest/1338/problem/A
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    int mx=0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(i)b[i]=max(b[i-1],a[i]);
        else b[i]=a[i];
        mx=max(b[i]-a[i],mx);
    }
    int ans = (mx?32-__builtin_clz(mx):0);
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