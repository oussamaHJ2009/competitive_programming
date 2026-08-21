//problem link: https://atcoder.jp/contests/abc466/tasks/abc466_g
//authored by a human (i guess?)


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    bool yes=1;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(a>0)yes=false;
    }
    if(yes)cout<<"Yes\n";
    else cout<<"No\n";
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