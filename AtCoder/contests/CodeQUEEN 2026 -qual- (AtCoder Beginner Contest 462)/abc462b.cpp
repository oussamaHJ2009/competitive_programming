//problem link: https://atcoder.jp/contests/abc462/tasks/abc462_b
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>>ans(n+1);
    for (int i = 1; i <= n; i++)
    {
        int k;cin>>k;
        for (int j = 0; j < k; j++)
        {
            int p;cin>>p;
            ans[p].push_back(i);
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        cout<<ans[i].size()<<' ';
        for (auto x:ans[i])
        {
            cout<<x<<' ';
        }
        cout<<'\n';
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