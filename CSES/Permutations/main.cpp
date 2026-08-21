#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    if(n==3 || n==2){cout<<"NO SOLUTION\n";return;}
    vector<int>ans;
    int x=2;
    while (x<=n)
    {
        ans.push_back(x);x+=2;
    }
    x=1;
    while (x<=n)
    {
        ans.push_back(x);x+=2;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<' ';
    }
    
    
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