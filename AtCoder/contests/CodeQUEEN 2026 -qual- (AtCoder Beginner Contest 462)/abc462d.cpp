//problem link: https://atcoder.jp/contests/abc462/tasks/abc462_d
//written by a rando


#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve() {
    int n,d;
    cin>>n>>d;
    vector<pair<int,int>>a(n);
    for (auto &[s,t]:a)
    {
        cin>>s>>t;
    }
    sort(a.begin(),a.end());
    vector<ll>pre(n+1);
    pre[0]=0;
    for (int i = 1; i <= n; i++)
    {
        pre[i]=pre[i-1]+a[i-1].second;
    }
    int l=0;
    ll ans=0;
    for (int r = 1; r < n; r++)
    {
        while (a[l].second < a[r].first+d && l<=r)
        {
            l++;
        }
        
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