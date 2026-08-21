//problem link: https://codeforces.com/contest/2233/problem/A
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    if(z*x>=n)cout<<(n+x+y-1)/(x+y)<<'\n';
    else{
        cout<<min((n+x+y-1)/(x+y),(n-(z*x) + 10*y + x -1)/(10*y + x) + z)<<'\n';
    }
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