#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,d;
    cin>>n>>d;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    bool ok=0;
    sort(a.begin(),a.end());
    for (int i = 0; i < n-1; i++)
    {
        if(a[i]-a[0]<=d && a[n-1]-a[i+1]<=d)ok=true;
    }
    cout<<(ok?"Yes":"No")<<'\n';
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