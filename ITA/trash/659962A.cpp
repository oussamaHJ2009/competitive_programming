/*
*created: 2026-08-11 at 19:16:37
*problem: A. Ferris Wheel, link: https://codeforces.com/group/lRRb3iToWJ/contest/659962/problem/A
*author: a human
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int l=0,r=n-1;
    int ans=0;
    while(l<=r){
        if(a[l]+a[r] <= x)l++;
        r--;
        ans++;
    }
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}