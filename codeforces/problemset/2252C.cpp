/*
*created: 2026-08-06 at 22:11:34
*problem: C. Risky Tower, link: https://codeforces.com/contest/2252/problem/C
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    vector<int>pre(n);
    vector<vector<int>>a(n,vector<int>(m));
    for(int i=0;i<n;i++)cin>>v[i];
    pre[0]=v[0];
    for(int i=0;i<n;i++){
        if(i)pre[i]=min(pre[i-1],v[i]);
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
        sort(a[i].begin(),a[i].end(),greater<int>());
    }
    int ans=m;
    priority_queue<int,vector<int>,greater<int>>q;
    ll S=0;

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            q.push(a[i][j]);
            S+=a[i][j];
            while(S-q.top()>=pre[i]){
                S-=q.top();
                q.pop();
                ans=min((int)q.size(),ans);
            }
        }
    }

    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}