//problem link: https://codeforces.com/contest/2245/problem/A
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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(2*k>n){
        cout<<"-1\n";
        return;
    }
    int ans=0;
    for(int i=0;i<k;i++){
        if(s[i]!='R')ans++;
    }
    for(int i=n-1;i>=n-k;i--){
        if(s[i]!='L')ans++;
    }
    cout<<ans<<'\n';
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