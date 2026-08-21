#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int a,b;
    cin>>a>>b;
    if(abs(a-b)%2==0)cout<<"Yes\n";
    else cout<<"No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}