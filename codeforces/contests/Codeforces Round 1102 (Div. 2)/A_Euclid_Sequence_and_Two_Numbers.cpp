#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    bool ok=1;
    for (int i = 0; i <= n-3; i++)
    {
        if(a[i]%a[i+1]!=a[i+2])ok=0;
    }
    if(ok){
        cout<<a[0]<<" "<<a[1]<<'\n';
    }else{
        cout<<-1<<'\n';
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