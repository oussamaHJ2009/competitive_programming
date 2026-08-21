//problem link: https://atcoder.jp/contests/abc463/tasks/abc463_b
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    char x;
    cin>>x;
    int idx=x-'A';
    bool yes=0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s[idx]=='o')yes=1;
    }
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