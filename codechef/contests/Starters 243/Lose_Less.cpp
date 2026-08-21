//problem link: https://www.codechef.com/START243D/problems/LOSELESS
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,m;
    cin>>m>>n;
    while (n>m && n>=3)
    {
        n-=3;m--;
    }
    cout<<max(0,m-n)<<'\n';
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