#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n+1);
    for (int i = 1; i <= n; i++)
    {
        a[i]=i;
    }
    for (int i = 1; i <= n-1; i+=2)
    {
        swap(a[i],a[i+1]);
    }
    if(n%2){
        swap(a[n-1],a[n]);
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    cout<<'\n';
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