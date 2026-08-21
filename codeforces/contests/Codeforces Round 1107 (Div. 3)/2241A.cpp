//problem link: https://codeforces.com/contest/2241/problem/A
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int x,y;
    cin>>x>>y;
    if(x%y==0)cout<<"Yes\n";
    else cout<<"No\n";
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