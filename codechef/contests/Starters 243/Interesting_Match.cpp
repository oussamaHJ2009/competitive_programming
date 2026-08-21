//problem link: https://www.codechef.com/START243D/problems/INTMTCH
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int x,y;
    cin>>x>>y;
    if(abs(x-y)<=2)cout<<"Interesting"<<'\n';
    else cout<<"Boring"<<'\n';
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