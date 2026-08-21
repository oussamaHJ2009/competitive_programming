#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(auto &x:a){
        cin>>x;
    }
    vector<bool>dp(k+1,false);
    for (int i = 0; i < k; i++)
    {
        for (auto x:a)
        {
            if(i+x<=k && !dp[i])dp[i+x]=true;
        }
    }
    
    cout<<(dp[k]?"First":"Second")<<'\n';
    
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