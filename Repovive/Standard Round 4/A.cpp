#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,d,x;
    cin>>n>>d>>x;
    if(d<min(x,n-x+1))cout<<"No\n";
    else cout<<"Yes\n";
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