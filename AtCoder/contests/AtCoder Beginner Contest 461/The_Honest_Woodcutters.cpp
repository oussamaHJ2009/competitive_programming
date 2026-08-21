#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<int>A(n+1),B(n+1);
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin>>B[i];
    }
    bool ans=true;
    for (int i = 1; i <= n; i++)
    {
        if(B[A[i]]!=i)ans=false;
    }
    cout<<(ans?"Yes":"No")<<'\n';
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