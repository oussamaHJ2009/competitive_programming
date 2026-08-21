//problem link: https://codeforces.com/contest/2247/problem/B
//authored by a human (i guess?)

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,m,k;
    cin>>n>>k>>m;
    if(k>m){
        cout<<"NO\n";
        return;
    }
    vector<int>a(n,m/k);
    for (int i = 0; i < m%k; i++)a[i]++;
    cout<<"YES\n";
    for(auto x:a)cout<<x<<' ';
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}