//problem link: https://atcoder.jp/contests/abc462/tasks/abc462_a
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    string s;
    cin>>s;
    string ans="";
    for (auto c:s)
    {
        if(c-'0'<=9)ans+=c;
    }
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