#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>a(101);
    bool ok=false;
    for (int i = 0; i < n; i++)
    {
        int x;cin>>x;
        a[x]++;
        if(a[x]>1)ok=true;
    }
    cout<<(ok?"YES":"NO")<<'\n';
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