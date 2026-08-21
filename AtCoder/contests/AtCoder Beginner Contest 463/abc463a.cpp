//problem link: https://atcoder.jp/contests/abc463/tasks/abc463_a
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int x,y;
    cin>>x>>y;
    bool yes = (x%16==0 && y%9==0 && x/16==y/9);
    cout<<(yes?"Yes\n":"No\n");
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